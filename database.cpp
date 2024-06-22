#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Database::Database() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("recipes.db");
}

bool Database::open() {
    return m_db.open();
}

void Database::close() {
    m_db.close();
}

bool Database::createRecipeTable() {
    QSqlQuery query;
    query.prepare("CREATE TABLE IF NOT EXISTS recipes ("
                  "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                  "name TEXT NOT NULL,"
                  "type TEXT,"
                  "cuisine TEXT,"
                  "ingredients TEXT,"
                  "instructions TEXT,"
                  "tags TEXT"
                  ")");
    return query.exec();
}

bool Database::addRecipe(const Recipe& recipe) {
    QSqlQuery query;
    query.prepare("INSERT INTO recipes (name, type, cuisine, ingredients, instructions, tags) "
                  "VALUES (:name, :type, :cuisine, :ingredients, :instructions, :tags)");
    query.bindValue(":name", recipe.getName());
    query.bindValue(":type", recipe.getType());
    query.bindValue(":cuisine", recipe.getCuisine());
    query.bindValue(":ingredients", recipe.getIngredients());
    query.bindValue(":instructions", recipe.getInstructions());
    query.bindValue(":tags", recipe.getTags().join(", "));
    return query.exec();
}

QList<Recipe> Database::getRecipes(const QString& type, const QString& cuisine, const QList<QString>& tags) {
    QList<Recipe> recipes;
    QSqlQuery query;
    QString queryString = "SELECT * FROM recipes WHERE 1=1";

    if (!type.isEmpty())
        queryString += " AND type = '" + type + "'";
    if (!cuisine.isEmpty())
        queryString += " AND cuisine = '" + cuisine + "'";
    if (!tags.isEmpty()) {
        for (const QString& tag : tags) {
            queryString += " AND tags LIKE '%" + tag + "%'";
        }
    }

    query.prepare(queryString);
    if (query.exec()) {
        while (query.next()) {
            Recipe recipe;
            recipe.setName(query.value("name").toString());
            recipe.setType(query.value("type").toString());
            recipe.setCuisine(query.value("cuisine").toString());
            recipe.setIngredients(query.value("ingredients").toString());
            recipe.setInstructions(query.value("instructions").toString());
            QStringList tagList = query.value("tags").toString().split(", ");
            recipe.setTags(tagList);  // Assuming setTags is appropriately implemented in Recipe
            recipes.append(recipe);
        }
    } else {
        qDebug() << "Error querying recipes:" << query.lastError().text();
    }

    return recipes;
}

// database.cpp
#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

QSqlDatabase Database::db = QSqlDatabase::addDatabase("QSQLITE");

bool Database::initialize()
{
    db.setDatabaseName("recipes.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to open database:" << db.lastError().text();
        return false;
    }

    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS recipes ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT,"
               "name TEXT NOT NULL,"
               "portion_size TEXT,"
               "ingredients TEXT,"
               "notes TEXT"
               ")");

    if (query.lastError().isValid()) {
        qDebug() << "Error: Failed to create table:" << query.lastError().text();
        return false;
    }

    return true;
}

bool Database::addRecipe(const QString &name, const QString &portionSize, const QList<QPair<QString, QString>> &ingredients, const QString &notes)
{
    QSqlQuery query;
    query.prepare("INSERT INTO recipes (name, portion_size, ingredients, notes) VALUES (:name, :portionSize, :ingredients, :notes)");
    query.bindValue(":name", name);
    query.bindValue(":portionSize", portionSize);

    QStringList ingredientList;
    for (const auto &ingredient : ingredients) {
        ingredientList.append(ingredient.first + ": " + ingredient.second);
    }
    query.bindValue(":ingredients", ingredientList.join("; "));

    query.bindValue(":notes", notes);

    if (!query.exec()) {
        qDebug() << "Error: Failed to add recipe:" << query.lastError().text();
        return false;
    }

    return true;
}

QList<Recipe> Database::filterRecipes(const QString &type)
{
    QList<Recipe> recipes;

    QSqlQuery query;
    query.prepare("SELECT * FROM recipes WHERE type = :type");
    query.bindValue(":type", type);

    if (query.exec()) {
        while (query.next()) {
            Recipe recipe;
            recipe.setId(query.value("id").toInt());
            recipe.setName(query.value("name").toString());
            recipe.setPortionSize(query.value("portion_size").toString());
            // Parse ingredients and notes as needed
            recipes.append(recipe);
        }
    } else {
        qDebug() << "Error: Failed to fetch recipes:" << query.lastError().text();
    }

    return recipes;
}

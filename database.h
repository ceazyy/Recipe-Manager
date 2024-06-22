#ifndef DATABASE_H
#define DATABASE_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "recipe.h"

class Database {
public:
    Database();
    bool open();
    void close();
    bool createRecipeTable();
    bool addRecipe(const Recipe& recipe);
    QList<Recipe> getRecipes(const QString& type, const QString& cuisine, const QList<QString>& tags);

private:
    QSqlDatabase m_db;
};

#endif // DATABASE_H

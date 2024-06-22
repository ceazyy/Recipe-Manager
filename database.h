#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QList> // Include QList for using QList<QPair<...>>

// Include QPair for using QPair<QString, QString>
#include <QPair>
#include <QString>
#include <recipe.h>

class Database
{
public:
    static bool initialize();
    static bool addRecipe(const QString &name, const QString &portionSize, const QList<QPair<QString, QString>> &ingredients, const QString &notes);
    static QList<Recipe> filterRecipes(const QString &type);

private:
    static QSqlDatabase db;
};

#endif // DATABASE_H

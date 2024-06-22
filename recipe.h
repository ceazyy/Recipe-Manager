#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QList>
#include <QPair>

class Recipe
{
public:
    Recipe();
    Recipe(const QString &name, const QString &portionSize, const QList<QPair<QString, QString>> &ingredients, const QString &notes);

    QString name() const;
    void setName(const QString &name);

    QString portionSize() const;
    void setPortionSize(const QString &portionSize);

    QList<QPair<QString, QString>> ingredients() const;
    void setIngredients(const QList<QPair<QString, QString>> &ingredients);

    QString notes() const;
    void setNotes(const QString &notes);

private:
    QString m_name;
    QString m_portionSize;
    QList<QPair<QString, QString>> m_ingredients;
    QString m_notes;
};

#endif // RECIPE_H

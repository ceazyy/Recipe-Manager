#ifndef RECIPE_H
#define RECIPE_H

#include <QString>
#include <QList>
#include <QSet>  // Include QSet header

class Recipe
{
public:
    Recipe();

    QString getName() const;
    void setName(const QString &value);

    QString getType() const;
    void setType(const QString &value);

    QString getCuisine() const;
    void setCuisine(const QString &value);

    QString getIngredients() const;
    void setIngredients(const QString &value);

    QString getInstructions() const;
    void setInstructions(const QString &value);

    QList<QString> getTags() const;
    void setTags(const QList<QString> &value);

private:
    QString name;
    QString type;
    QString cuisine;
    QString ingredients;
    QString instructions;
    QList<QString> tags;  // Use QList<QString> for tags
};

#endif // RECIPE_H

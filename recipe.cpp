#include "recipe.h"

Recipe::Recipe()
{
}

QString Recipe::getName() const
{
    return name;
}

void Recipe::setName(const QString &value)
{
    name = value;
}

QString Recipe::getType() const
{
    return type;
}

void Recipe::setType(const QString &value)
{
    type = value;
}

QString Recipe::getCuisine() const
{
    return cuisine;
}

void Recipe::setCuisine(const QString &value)
{
    cuisine = value;
}

QString Recipe::getIngredients() const
{
    return ingredients;
}

void Recipe::setIngredients(const QString &value)
{
    ingredients = value;
}

QString Recipe::getInstructions() const
{
    return instructions;
}

void Recipe::setInstructions(const QString &value)
{
    instructions = value;
}

QList<QString> Recipe::getTags() const
{
    return tags;
}

void Recipe::setTags(const QList<QString> &value)
{
    tags = value;
}

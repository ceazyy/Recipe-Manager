#include "browserecipewindow.h"
#include "ui_browserecipewindow.h"
#include <QMessageBox>

BrowseRecipeWindow::BrowseRecipeWindow(Database *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseRecipeWindow),
    database(db),
    recipeModel(new QStandardItemModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel(recipeModel);

    QStringList types = {"Vegetarian", "Non-Vegetarian", "Vegan"};
    ui->typeComboBox->addItems(types);

    // Initial display of all recipes
    QList<Recipe> allRecipes = database->getRecipes("", "", QList<QString>());
    displayRecipes(allRecipes);

    connect(ui->backButton, &QPushButton::clicked, this, &BrowseRecipeWindow::on_backButton_clicked);
}

BrowseRecipeWindow::~BrowseRecipeWindow()
{
    delete ui;
}

void BrowseRecipeWindow::on_filterButton_clicked()
{
    QString type = ui->typeComboBox->currentText();
    QString cuisine = ui->cuisineLineEdit->text();
    QStringList tags = ui->tagsLineEdit->text().split(",", QString::SkipEmptyParts);

    QList<Recipe> filteredRecipes = database->getRecipes(type, cuisine, tags);
    displayRecipes(filteredRecipes);
}

void BrowseRecipeWindow::on_backButton_clicked()
{
    close();  // Close the current window
}

void BrowseRecipeWindow::displayRecipes(const QList<Recipe> &recipes)
{
    recipeModel->clear();
    recipeModel->setColumnCount(6);
    recipeModel->setHorizontalHeaderLabels({"Name", "Type", "Cuisine", "Ingredients", "Instructions", "Tags"});

    for (const Recipe &recipe : recipes) {
        QList<QStandardItem *> rowItems;
        rowItems.append(new QStandardItem(recipe.getName()));
        rowItems.append(new QStandardItem(recipe.getType()));
        rowItems.append(new QStandardItem(recipe.getCuisine()));
        rowItems.append(new QStandardItem(recipe.getIngredients()));
        rowItems.append(new QStandardItem(recipe.getInstructions()));
        rowItems.append(new QStandardItem(recipe.getTags().join(", ")));
        recipeModel->appendRow(rowItems);
    }

    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

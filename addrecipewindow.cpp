#include "addrecipewindow.h"
#include "ui_addrecipewindow.h"
#include <QMessageBox>

AddRecipeWindow::AddRecipeWindow(Database *db, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecipeWindow),
    database(db)
{
    ui->setupUi(this);

    QStringList types = {"Vegetarian", "Non-Vegetarian", "Vegan"};
    ui->typeComboBox->addItems(types);

    connect(ui->backButton, &QPushButton::clicked, this, &AddRecipeWindow::on_backButton_clicked);
}

AddRecipeWindow::~AddRecipeWindow()
{
    delete ui;
}

void AddRecipeWindow::on_addButton_clicked()
{
    Recipe recipe;
    recipe.setName(ui->nameLineEdit->text());
    recipe.setType(ui->typeComboBox->currentText());
    recipe.setCuisine(ui->cuisineLineEdit->text());
    recipe.setIngredients(ui->ingredientsTextEdit->toPlainText());
    recipe.setInstructions(ui->instructionsTextEdit->toPlainText());
    QStringList tagsList = ui->tagsLineEdit->text().split(",", QString::SkipEmptyParts);
    recipe.setTags(tagsList);

    if (database->addRecipe(recipe)) {
        QMessageBox::information(this, "Success", "Recipe added successfully.");
        close();
    } else {
        QMessageBox::warning(this, "Error", "Failed to add recipe. Please try again.");
    }
}

void AddRecipeWindow::on_backButton_clicked()
{
    close();  // Close the current window
}

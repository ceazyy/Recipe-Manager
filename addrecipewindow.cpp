#include "addrecipewindow.h"
#include "ui_addrecipewindow.h"
#include <QMessageBox>
#include <QSet>  // Ensure QSet is included

AddRecipeWindow::AddRecipeWindow(Database *db, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddRecipeWindow)
    , database(db)
{
    ui->setupUi(this);
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
    recipe.setTags(tagsList);  // Set tags using QList<QString>
    database->addRecipe(recipe);
    close();
}

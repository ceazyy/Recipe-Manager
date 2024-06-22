// addrecipedialog.cpp
#include "addrecipedialog.h"
#include "ui_addrecipedialog.h"

AddRecipeDialog::AddRecipeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRecipeDialog)
{
    ui->setupUi(this);
}

AddRecipeDialog::~AddRecipeDialog()
{
    delete ui;
}

void AddRecipeDialog::clearFields()
{
    // Implement clearing fields logic if needed
}

void AddRecipeDialog::on_finishRecipeButton_clicked()
{
    QString name = ui->dishNameLineEdit->text();
    QString portionSize = ui->portionSizeLineEdit->text();
    // Retrieve ingredients from a list view or table
    QList<QPair<QString, QString>> ingredients;
    // Add logic to collect ingredients from UI
    QString notes = ui->notesTextEdit->toPlainText();

    emit recipeAdded(name, portionSize, ingredients, notes);
    close();
}

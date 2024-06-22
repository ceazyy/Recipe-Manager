#ifndef ADDRECIPEWINDOW_H
#define ADDRECIPEWINDOW_H

#include <QDialog>
#include "database.h"  // Include your Database class header
#include "recipe.h"    // Include your Recipe class header

namespace Ui {
class AddRecipeWindow;
}

class AddRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipeWindow(Database *db, QWidget *parent = nullptr);
    ~AddRecipeWindow();

private slots:
    void on_addButton_clicked();
    void on_backButton_clicked();  // New slot for back button

private:
    Ui::AddRecipeWindow *ui;
    Database *database;
};

#endif // ADDRECIPEWINDOW_H

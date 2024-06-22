#ifndef BROWSERECIPEWINDOW_H
#define BROWSERECIPEWINDOW_H

#include <QDialog>
#include <QStandardItemModel>
#include "database.h"  // Include your Database class header
#include "recipe.h"    // Include your Recipe class header

namespace Ui {
class BrowseRecipeWindow;
}

class BrowseRecipeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit BrowseRecipeWindow(Database *db, QWidget *parent = nullptr);
    ~BrowseRecipeWindow();

private slots:
    void on_filterButton_clicked();
    void on_backButton_clicked();  // New slot for back button

private:
    Ui::BrowseRecipeWindow *ui;
    Database *database;
    QStandardItemModel *recipeModel;

    void displayRecipes(const QList<Recipe> &recipes);
};

#endif // BROWSERECIPEWINDOW_H

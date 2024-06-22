#ifndef ADDRECIPEWINDOW_H
#define ADDRECIPEWINDOW_H

#include <QDialog>
#include "database.h"

namespace Ui {
class AddRecipeWindow;
}

class AddRecipeWindow : public QDialog {
    Q_OBJECT

public:
    explicit AddRecipeWindow(Database *db, QWidget *parent = nullptr);
    ~AddRecipeWindow();

private slots:
    void on_addButton_clicked();

private:
    Ui::AddRecipeWindow *ui;
    Database *database;
};

#endif // ADDRECIPEWINDOW_H

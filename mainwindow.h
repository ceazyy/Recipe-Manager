#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addrecipewindow.h"
#include "browserecipewindow.h"
#include "database.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addRecipeButton_clicked();
    void on_browseRecipesButton_clicked();

private:
    Ui::MainWindow *ui;
    AddRecipeWindow *addRecipeWindow;
    BrowseRecipeWindow *browseRecipeWindow;
    Database *database;
};

#endif // MAINWINDOW_H

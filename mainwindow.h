// mainwindow.h
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "addrecipedialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openAddRecipeDialog();
    void addRecipe(QString name, QString portionSize, QList<QPair<QString, QString>> ingredients, QString notes);

private:
    Ui::MainWindow *ui;
    AddRecipeDialog *addRecipeDialog;
    // Add data structures or SQLite database connection here
};

#endif // MAINWINDOW_H

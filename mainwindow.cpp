#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    database = new Database();
    if (!database->open()) {
        qDebug() << "Error: Failed to connect to database.";
        // Handle error
    }
    database->createRecipeTable();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete database;
}

void MainWindow::on_addRecipeButton_clicked() {
    addRecipeWindow = new AddRecipeWindow(database);
    addRecipeWindow->show();
}

void MainWindow::on_browseRecipesButton_clicked() {
    browseRecipeWindow = new BrowseRecipeWindow(database);
    browseRecipeWindow->show();
}

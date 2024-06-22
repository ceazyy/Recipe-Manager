// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    addRecipeDialog = new AddRecipeDialog(this);

    connect(ui->addRecipeButton, &QPushButton::clicked, this, &MainWindow::openAddRecipeDialog);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openAddRecipeDialog()
{
    addRecipeDialog->clearFields(); // Optional: Clear fields if dialog is reused
    addRecipeDialog->show();
}

void MainWindow::addRecipe(QString name, QString portionSize, QList<QPair<QString, QString>> ingredients, QString notes)
{
    // Handle adding recipe data here (e.g., add to database or store in memory)
    // Update UI to reflect new recipe added
}


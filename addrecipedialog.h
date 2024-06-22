// addrecipedialog.h
#ifndef ADDRECIPEDIALOG_H
#define ADDRECIPEDIALOG_H

#include <QDialog>

namespace Ui {
class AddRecipeDialog;
}

class AddRecipeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddRecipeDialog(QWidget *parent = nullptr);
    ~AddRecipeDialog();
    void clearFields(); // Optional: Clear fields when dialog is reopened

signals:
    void recipeAdded(QString name, QString portionSize, QList<QPair<QString, QString>> ingredients, QString notes);

private slots:
    void on_finishRecipeButton_clicked();

private:
    Ui::AddRecipeDialog *ui;
};

#endif // ADDRECIPEDIALOG_H

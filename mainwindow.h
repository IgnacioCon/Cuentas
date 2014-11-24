#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "account.h"

#include <QIODevice>
#include <QFile>
#include <QDir>
#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void onClickAdd();
    void onClickBack();
    void onClickNext();
    void onClickClear();
    void onClickSave();

private:
    Ui::MainWindow *ui;
    QVector<Account> cuentas;

};

#endif // MAINWINDOW_H

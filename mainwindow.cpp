#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->id_lineEdit->setEnabled(false);
    ui->id_lineEdit->setText(QString::number(cuentas.size()));
//    ui->male_radioButton->toggle();

    connect(ui->add_pushButton,SIGNAL(clicked()),this,SLOT(onClickAdd()));
    connect(ui->back_pushButton,SIGNAL(clicked()),this,SLOT(onClickBack()));
    connect(ui->next_pushButton,SIGNAL(clicked()),this,SLOT(onClickNext()));
    connect(ui->clear_pushButton,SIGNAL(clicked()),this,SLOT(onClickClear()));
    connect(ui->save_pushButton,SIGNAL(clicked()),this,SLOT(onClickSave()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClickAdd()
{
    Account cuenta;

    cuenta.setId(cuentas.size());
    cuenta.setName(ui->name_lineEdit->text().toStdString());
    cuenta.setLastname(ui->lastname_lineEdi->text().toStdString());
    cuenta.setSex(ui->male_radioButton->isChecked());
    //cuenta.setSex(ui->female_radioButton->isDown());
    cuenta.setAge(ui->age_lineEdit->text().toFloat());
    cuenta.setBalance(ui->balance_lineEdit->text().toDouble());

    cuentas.push_back(cuenta);

    ui->id_lineEdit->setText(QString::number(cuentas.size()));
    ui->name_lineEdit->setText("");
    ui->lastname_lineEdi->setText("");

    ui->age_lineEdit->setText("");
    ui->balance_lineEdit->setText("");


}

void MainWindow::onClickBack()
{
    Account cuenta;

    int id = ui->id_lineEdit->text().toInt()-1;

    if(id <= 0)
    {
        id = 0;
    }

    cuenta = cuentas[id];


    ui->id_lineEdit->setText(QString::number(cuenta.getId()));
    ui->name_lineEdit->setText(QString::fromStdString(cuenta.getName()));
    ui->lastname_lineEdi->setText(QString::fromStdString(cuenta.getLastname()));
    if(cuenta.getSex())
    {
        ui->male_radioButton->toggle();
    }
    else{
        ui->female_radioButton->toggle();
    }

    ui->age_lineEdit->setText(QString::number(cuenta.getAge()));
    ui->balance_lineEdit->setText(QString::number(cuenta.getBalance()));



}

void MainWindow::onClickNext()
{
    Account cuenta;

    int id = ui->id_lineEdit->text().toInt()+1;

    if(cuentas.size() == 1)
    {
        id = 0;
    }
    if(id >= cuentas.size())
    {
        id = cuentas.size()-1;
    }

    cuenta = cuentas[id];


    ui->id_lineEdit->setText(QString::number(cuenta.getId()));
    ui->name_lineEdit->setText(QString::fromStdString(cuenta.getName()));
    ui->lastname_lineEdi->setText(QString::fromStdString(cuenta.getLastname()));
    if(cuenta.getSex())
    {
        ui->male_radioButton->toggle();
    }
    else{
        ui->female_radioButton->toggle();
    }

    ui->age_lineEdit->setText(QString::number(cuenta.getAge()));
    ui->balance_lineEdit->setText(QString::number(cuenta.getBalance()));

}

void MainWindow::onClickClear()
{

         ui->id_lineEdit->setText(QString::number(cuentas.size()));
         ui->name_lineEdit->setText("");
         ui->lastname_lineEdi->setText("");

         ui->age_lineEdit->setText("");
         ui->balance_lineEdit->setText("");

}

void MainWindow::onClickSave()
{
    QString filename = QFileDialog::getSaveFileName(this, "Select Directory");
    qDebug()<<filename;


    QFile sFile;

    sFile.setFileName(filename);

    if(sFile.open(QIODevice::ReadWrite))
    {
        QTextStream out(&sFile);

       for(int i=0; i<cuentas.size();i++)
       {
           out<<cuentas[i].getId()<<","<<QString::fromStdString(cuentas[i].getName())<<","<<QString::fromStdString(cuentas[i].getLastname())<<","<<cuentas[i].getSex()<<","<<cuentas[i].getAge()<<","<<cuentas[i].getBalance()<<endl;

       }

    }

}


#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QIntValidator>
#include <QMessageBox>
#include <iostream>
#include <vector>
//#include "HashTable.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->keyEdit->setValidator(new QIntValidator {0, INT_MAX});
    ui->keyEdit->setText("0");
    ui->valueEdit->setValidator(new QIntValidator {0, INT_MAX});
    ui->valueEdit->setText("0");
    ui->resizeEdit->setValidator(new QIntValidator {0, INT_MAX});
    ui->resizeEdit->setText("0");
    ui->keyForDelete->setValidator(new QIntValidator {0, INT_MAX});
    ui->keyForDelete->setText("0");
    ui->tableWidget->setColumnCount(2);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Key" << "Value");
    ui->deleteValueButton->setEnabled(false);
    ui->addValueButton->setEnabled(false);

    QObject::connect(ui->addValueButton, &QPushButton::clicked, this, &MainWindow::on_clicked_addValue);
    QObject::connect(ui->deleteValueButton, &QPushButton::clicked, this, &MainWindow::on_clicked_deleteValue);
    QObject::connect(ui->resizeButton, &QPushButton::clicked, this, &MainWindow::on_clicked_resize);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clicked_addValue()
{
    bool ok1;
    int key = ui->keyEdit->text().toInt(&ok1);
    bool ok2;
    int value = ui->valueEdit->text().toInt(&ok2);
    if(ok1 && ok2)
    {
        int hash = table.addValue(key, value);
        std::cout << "table" << std::endl;
        table.printTable();
        if(hash != -1)
        {
            QTableWidgetItem *tbl1 = new QTableWidgetItem(QString::number(key));
            ui->tableWidget->setItem(hash, 0, tbl1);

            QTableWidgetItem *tbl2 = new QTableWidgetItem(QString::number(value));
            ui->tableWidget->setItem(hash, 1, tbl2);

        }
        else
            displayError(QString {"addValue: all hashes for this key allready taken"});
    }
    else
        displayError(QString {"addValue: invalid key value: must be an integer"});
}


void MainWindow::on_clicked_deleteValue()
{

    bool ok;
    int K = ui->keyForDelete->text().toInt(&ok);
    if(ok)
    {
        if(table.checkKey(K) != -1)
        {
            int hash = table.checkKey(K);

            QTableWidgetItem *tbl1 = new QTableWidgetItem(QString::fromStdString(""));
            ui->tableWidget->setItem(hash, 0, tbl1);

             QTableWidgetItem *tbl2 = new QTableWidgetItem(QString::fromStdString(""));
            ui->tableWidget->setItem(hash, 1, tbl2);

            table.deleteTableByKey(K);
        }
        else
           displayError(QString {"deleteValue: this key not found"});
    }
    else
        displayError(QString {"deleteValue: invalid key value: must be an integer"});

    table.printTable();


}

void MainWindow::on_clicked_resize()
{

    bool ok;
    int size = ui->resizeEdit->text().toInt(&ok);

    if(ok)
    {
        ui->deleteValueButton->setEnabled(false);
        ui->addValueButton->setEnabled(false);

        table.resize(size);
        ui->tableWidget->setRowCount(size);

        if(size > 0)
        {
            ui->deleteValueButton->setEnabled(true);
            ui->addValueButton->setEnabled(true);
        }
    }
    else
    {
         displayError(QString {"resize: invalid key value: must be an integer"});
    }

}


void MainWindow::displayError(QString const& msg)
{
    QMessageBox::warning(this, "error", msg);
}

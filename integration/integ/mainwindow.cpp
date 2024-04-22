#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_clicked()
{
    hide();
    Pageevenement = new pageevenement (this);
    Pageevenement->show();

}

void MainWindow::on_pushButton_6_clicked()
{
    hide();
    Pagetransaction = new pagetransaction (this);
    Pagetransaction->show();

}

void MainWindow::on_pushButton_3_clicked()
{
    hide();
    pageoeuvre = new Pageoeuvre (this);
    pageoeuvre->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Pageartiste = new pageartiste (this);
    Pageartiste->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    hide();
    Pageclient = new  pageclient(this);
    Pageclient->show();
}

void MainWindow::on_pushButton_clicked()
{
    hide();
    Pagepersonnel = new pagepersonnel(this);
    Pagepersonnel->show();
}

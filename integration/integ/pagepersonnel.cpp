#include "pagepersonnel.h"
#include "ui_pagepersonnel.h"
#include<QLabel>
#include<QMessageBox>
#include<QVBoxLayout>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QSqlQueryModel>
#include<QApplication>
#include <iostream>
#include<QIntValidator>
#include<QBoxLayout>
#include<QLineEdit>
#include<QComboBox>
#include<QMessageBox>
#include <QApplication>
#include <QDebug>
#include<QWidget>
#include <pers.h>
#include "mainwindow.h"
#include <mainwindow.h>
#include <QSortFilterProxyModel>

pagepersonnel::pagepersonnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pagepersonnel),
    selectedPersRow(-1),
    P(),
    proxyModel(new QSortFilterProxyModel())


{
    ui->setupUi(this);

    ui->id_p->setValidator(new QIntValidator(0, 99999999, this));




    // Assuming afficher() returns a QSqlQueryModel
    QSqlQueryModel *model = P.afficher();
      proxyModel->setSourceModel(model);

    QStandardItemModel *standardModel = new QStandardItemModel(model->rowCount(), model->columnCount(), this);

    // Set the horizontal header names to match the database column names
    for (int col = 0; col < model->columnCount(); ++col) {
        standardModel->setHorizontalHeaderItem(col, new QStandardItem(model->headerData(col, Qt::Horizontal).toString()));
    }

    // Populate the table with data
    for (int row = 0; row < model->rowCount(); ++row) {
        for (int col = 0; col < model->columnCount(); ++col) {
            QModelIndex index = model->index(row, col);
            QString data = model->data(index).toString();
            QStandardItem *item = new QStandardItem(data);
            standardModel->setItem(row, col, item);
        }
    }

    ui->tab_pers->setModel(standardModel);

    // Connect the clicked signal to the custom slot for handling selection change
    connect(ui->tab_pers->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));
}

pagepersonnel::~pagepersonnel()
{
    delete ui;

        delete proxyModel;
}

void pagepersonnel::on_pb_ajouter_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Confirmation");
    msgBox.setInformativeText("Are you sure you want to add?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int reply = msgBox.exec();
    if (reply == QMessageBox::Cancel) {
        return;
    }

    int id_p = ui->id_p->text().toInt();
    QString email_p = ui->email_p->text();
    QString password_p = ui->password_p->text();
    QString nom_p = ui->nom_p->text();
    QString dateemb_p = ui->dateemb_p->text();
    int salaire_p = ui->salaire_p->text().toInt();

    if (ui->id_p->text().isEmpty() || ui->email_p->text().isEmpty()
        || ui->password_p->text().isEmpty() || ui->nom_p->text().isEmpty()
        || ui->dateemb_p->text().isEmpty() || ui->salaire_p->text().isEmpty()){
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }





    Pers P(id_p,email_p, password_p, nom_p ,dateemb_p, salaire_p);
    bool test = P.ajouter();
    if (test)
    {
        ui->tab_pers->setModel(P.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Ajout effectué. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, QObject::tr("NOT OK"),
                           QObject::tr("Ajout non effectué. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();
    }
}
void pagepersonnel::on_pb_supprimer_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Confirmation");
    msgBox.setInformativeText("Are you sure you want to delete?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int reply = msgBox.exec();
    if (reply == QMessageBox::Cancel) {
        return;
    }

   Pers P;


    int id_p = ui->id_p->text().toInt();
   P.setid_p(id_p);

    bool exists = P.checkIfPersExists(id_p);
    if (!exists) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("L'event n'a pas été trouvé dans la base de données.").arg(id_p),
                              QMessageBox::Cancel);
        return;
    }

    bool test = P.supprimer(id_p);
    if (test)
    {
        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Suppression effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();

        ui->tab_pers->setModel(P.afficher());
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, QObject::tr("Erreur"),
                           QObject::tr("Suppression non effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();
    }
}


void pagepersonnel::on_pb_modifier_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Confirmation");
    msgBox.setInformativeText("Are you sure you want to modify?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);

    int reply = msgBox.exec();
    if (reply == QMessageBox::Cancel) {
        return;
    }

    if (selectedPersRow == -1) {

        QMessageBox::warning(this, tr("Aucun person sélectionné"),
                             tr("Veuillez sélectionner un personne à modifier."), QMessageBox::Ok);
        return;
    }

    int id_p = ui->id_p->text().toInt();
    QString email_p = ui->email_p->text();
    QString password_p = ui->password_p->text();
    QString nom_p = ui->nom_p->text();
    QString dateemb_p = ui->dateemb_p->text();
    int salaire_p = ui->salaire_p->text().toInt();

    if (ui->id_p->text().isEmpty() || ui->email_p->text().isEmpty()
        || ui->password_p->text().isEmpty() || ui->nom_p->text().isEmpty()
        || ui->dateemb_p->text().isEmpty() || ui->salaire_p->text().isEmpty()){
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    QModelIndex index = ui->tab_pers->model()->index(selectedPersRow, 0); // Assuming the first column contains the primary key
    QString pers_id = ui->tab_pers->model()->data(index).toString();

    Pers persToUpdate(id_p, email_p, password_p, nom_p,dateemb_p, salaire_p);
    bool test = persToUpdate.modifierE(pers_id.toInt());

    if (test)
    {
        ui->tab_pers->setModel(persToUpdate.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Modification effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        connect(&msgBox, &QMessageBox::finished, this, &pagepersonnel::handleMessageBoxResult);

        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, QObject::tr("Erreur"),
                           QObject::tr("personnel non trouvé ou modification non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();
    }
}

void pagepersonnel::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel)
    {

    }
}

void pagepersonnel::on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);

    // Get the selected row
    selectedPersRow = current.row();

    // Fill the line edits with the data from the selected row
    ui->id_p->setText(ui->tab_pers->model()->index(selectedPersRow, 0).data().toString());
    ui->email_p->setText(ui->tab_pers->model()->index(selectedPersRow, 1).data().toString());
    ui->password_p->setText(ui->tab_pers->model()->index(selectedPersRow, 2).data().toString());
    ui->nom_p->setText(ui->tab_pers->model()->index(selectedPersRow, 3).data().toString());
    ui->dateemb_p->setText(ui->tab_pers->model()->index(selectedPersRow, 4).data().toString());
     ui->salaire_p->setText(ui->tab_pers->model()->index(selectedPersRow, 5).data().toString());

}




void pagepersonnel::on_commandLinkButton_24_clicked()
{

    hide();
    Mainw = new MainWindow(this);
    Mainw->show();
}

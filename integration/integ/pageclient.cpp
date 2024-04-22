#include "pageclient.h"
#include "ui_pageclient.h"
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
#include <event.h>
#include "mainwindow.h"
#include <mainwindow.h>
#include <QSortFilterProxyModel>

pageclient::pageclient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pageclient),
    selectedClientRow(-1),
    C(),
    proxyModel(new QSortFilterProxyModel())


{
    ui->setupUi(this);

    ui->id_c->setValidator(new QIntValidator(0, 99999999, this));
     ui->telephone_c->setValidator(new QIntValidator(0, 99999999, this));



    // Assuming afficher() returns a QSqlQueryModel
    QSqlQueryModel *model = C.afficher();
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

    ui->tab_clients->setModel(standardModel);

    // Connect the clicked signal to the custom slot for handling selection change
    connect(ui->tab_clients->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));
}

pageclient::~pageclient()
{
    delete ui;

        delete proxyModel;
}

void pageclient::on_pb_ajouter_clicked()
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

    int id_c = ui->id_c->text().toInt();
    QString nom_c = ui->nom_c->text();
    QString adresse_c = ui->adresse_c->text();
    QString email_c = ui->email_c->text();
    int telephone_c = ui->telephone_c->text().toInt();
    int budget_c = ui->budget_c->text().toInt();

    if (ui->id_c->text().isEmpty() || ui->nom_c->text().isEmpty()
        || ui->adresse_c->text().isEmpty() || ui->email_c->text().isEmpty()
        || ui->telephone_c->text().isEmpty() || ui->budget_c->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }


   int id_t = ui->id_t->text().toInt();
    Client C(id_c, nom_c, adresse_c, email_c, telephone_c, budget_c);
     C.setid_t(id_t);
    bool test = C.ajouter();
    if (test)
    {
        ui->tab_clients->setModel(C.afficher());

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
void pageclient::on_pb_supprimer_clicked()
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

    Client C;


    int id_c= ui->id_c->text().toInt();
    C.setid_c(id_c);

    bool exists = C.checkIfClientExists(id_c);
    if (!exists) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("L'event n'a pas été trouvé dans la base de données.").arg(id_c),
                              QMessageBox::Cancel);
        return;
    }

    bool test = C.supprimer(id_c);
    if (test)
    {
        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Suppression effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();

        ui->tab_clients->setModel(C.afficher());
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


void pageclient::on_pb_modifier_clicked()
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

    if (selectedClientRow == -1) {

        QMessageBox::warning(this, tr("Aucun client sélectionné"),
                             tr("Veuillez sélectionner un client à modifier."), QMessageBox::Ok);
        return;
    }

    int id_c = ui->id_c->text().toInt();
    QString nom_c = ui->nom_c->text();
    QString adresse_c = ui->adresse_c->text();
    QString email_c = ui->email_c->text();
    int telephone_c = ui->telephone_c->text().toInt();
    int budget_c = ui->budget_c->text().toInt();

    if (ui->id_c->text().isEmpty() || ui->nom_c->text().isEmpty()
        || ui->adresse_c->text().isEmpty() || ui->email_c->text().isEmpty()
        || ui->telephone_c->text().isEmpty() || ui->budget_c->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    QModelIndex index = ui->tab_clients->model()->index(selectedClientRow, 0); // Assuming the first column contains the primary key
    QString client_id = ui->tab_clients->model()->data(index).toString();

     int id_t = ui->id_t->text().toInt();
    Client clientToUpdate(id_c, nom_c, adresse_c, email_c, telephone_c, budget_c);
       C.setid_t(id_t);
    bool test = clientToUpdate.modifierE(client_id.toInt());

    if (test)
    {
        ui->tab_clients->setModel(clientToUpdate.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Modification effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, &QMessageBox::finished, this, &pageclient::handleMessageBoxResult);

        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, QObject::tr("Erreur"),
                           QObject::tr("client non trouvé ou modification non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();
    }
}

void pageclient::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel)
    {
        // User clicked Cancel, do something if needed
    }
}

void pageclient::on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);


    selectedClientRow = current.row();

    ui->id_c->setText(ui->tab_clients->model()->index(selectedClientRow, 0).data().toString());
    ui->nom_c->setText(ui->tab_clients->model()->index(selectedClientRow, 1).data().toString());
    ui->adresse_c->setText(ui->tab_clients->model()->index(selectedClientRow, 2).data().toString());
    ui->email_c->setText(ui->tab_clients->model()->index(selectedClientRow, 3).data().toString());
    ui->telephone_c->setText(ui->tab_clients->model()->index(selectedClientRow, 4).data().toString());

}



void pageclient::on_commandLinkButton_24_clicked()
{
    hide();
    Mainw = new MainWindow(this);
    Mainw->show();
}

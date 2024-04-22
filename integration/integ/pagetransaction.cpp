#include "pagetransaction.h"
#include "ui_pagetransaction.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
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
#include <transactions.h>
#include <QSortFilterProxyModel>

pagetransaction::pagetransaction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pagetransaction),
    selectedTransRow(-1),
    T(),
    proxyModel(new QSortFilterProxyModel())


{
    ui->setupUi(this);

    ui->id_t->setValidator(new QIntValidator(0, 99999999, this));
     ui->montant_t->setValidator(new QIntValidator(0, 99999999, this));



    // Assuming afficher() returns a QSqlQueryModel
    QSqlQueryModel *model = T.afficher();
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

    ui->tab_trans->setModel(standardModel);

    // Connect the clicked signal to the custom slot for handling selection change
    connect(ui->tab_trans->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));
}
pagetransaction::~pagetransaction()
{
    delete ui;

        delete proxyModel;
}

void pagetransaction::on_pb_ajouter_clicked()
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
    int id_t = ui->id_t->text().toInt();
    int montant_t = ui->montant_t->text().toInt();
    int date_t = ui->date_t->text().toInt();
    QString statutpaiment_t = ui->statutpaiment_t->text();
    QString type_t = ui->type_t->text();

    if (ui->id_t->text().isEmpty() || ui->montant_t->text().isEmpty()
        || ui->date_t->text().isEmpty() || ui->statutpaiment_t->text().isEmpty()
        || ui->type_t->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }


    // Character-only Validation
    QRegularExpression characterRegex("^[a-zA-Zéèêëàâäîïôöûüç -]*$");

    if (!characterRegex.match(statutpaiment_t).hasMatch() || !characterRegex.match(type_t).hasMatch()) {
        QMessageBox::warning(this, tr("Caractères invalides"),
                             tr("Veuillez utiliser uniquement des caractères alphabétiques pour le nom, le prénom et l'adresse."), QMessageBox::Ok);
        return;
    }

    Transaction T(id_t, montant_t, date_t, statutpaiment_t, type_t);
    bool test = T.ajouter();
    if (test)
    {
        ui->tab_trans->setModel(T.afficher());

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
void pagetransaction::on_pb_supprimer_clicked()
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

    Transaction T;

    int id_t = ui->id_t->text().toInt();
    T.setid_t(id_t);

    bool exists = T.checkIfTransExists(id_t);

    if (!exists) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("L'event n'a pas été trouvé dans la base de données.").arg(id_t),
                              QMessageBox::Cancel);
        return;
    }

    bool test = T.supprimer(id_t);
    if (test)
    {
        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Suppression effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();

        ui->tab_trans->setModel(T.afficher());
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


void pagetransaction::on_pb_modifier_clicked()
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

    if (selectedTransRow == -1) {
        QMessageBox::warning(this, tr("Aucun transaction sélectionné"),
                             tr("Veuillez sélectionner un employé à modifier."), QMessageBox::Ok);
        return;
    }

    int id_t = ui->id_t->text().toInt();
    int montant_t = ui->montant_t->text().toInt();
    int date_t = ui->date_t->text().toInt();
    QString statutpaiment_t = ui->statutpaiment_t->text();
    QString type_t = ui->type_t->text();

    if (ui->id_t->text().isEmpty() || ui->montant_t->text().isEmpty()
        || ui->date_t->text().isEmpty() || ui->statutpaiment_t->text().isEmpty()
        || ui->type_t->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    QModelIndex index = ui->tab_trans->model()->index(selectedTransRow, 0); // Assuming the first column contains the primary key
    QString Transaction_id = ui->tab_trans->model()->data(index).toString();

    Transaction transToUpdate(id_t, montant_t, date_t, statutpaiment_t, type_t);
    bool test = transToUpdate.modifierE(id_t);
    if (test)
    {
        ui->tab_trans->setModel(transToUpdate.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Modification effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, &QMessageBox::finished, this, &pagetransaction::handleMessageBoxResult);

        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, QObject::tr("Erreur"),
                           QObject::tr("Employé non trouvé ou modification non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();
    }
}

void pagetransaction::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel)
    {
        // User clicked Cancel, do something if needed
    }
}

void pagetransaction::on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);

    // Get the selected row
    selectedTransRow = current.row();

    // Fill the line edits with the data from the selected row
    ui->id_t->setText(ui->tab_trans->model()->index(selectedTransRow, 0).data().toString());
    ui->montant_t->setText(ui->tab_trans->model()->index(selectedTransRow, 1).data().toString());
    ui->date_t->setText(ui->tab_trans->model()->index(selectedTransRow, 2).data().toString());
    ui->statutpaiment_t->setText(ui->tab_trans->model()->index(selectedTransRow, 3).data().toString());
    ui->type_t->setText(ui->tab_trans->model()->index(selectedTransRow, 4).data().toString());
  ;

}




void pagetransaction::on_commandLinkButton_24_clicked()
{
    hide();
    Mainw = new MainWindow(this);
    Mainw->show();
}

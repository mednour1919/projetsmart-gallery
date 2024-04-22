#include "pageartiste.h"
#include "ui_pageartiste.h"
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
#include <artiste.h>
#include "mainwindow.h"
#include <mainwindow.h>
#include <QSortFilterProxyModel>

pageartiste::pageartiste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pageartiste),
    selectedArtisteRow(-1),
    A(),
    proxyModel(new QSortFilterProxyModel())


{
    ui->setupUi(this);





    // Assuming afficher() returns a QSqlQueryModel
    QSqlQueryModel *model = A.afficher();
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

    ui->tab_artist->setModel(standardModel);

    // Connect the clicked signal to the custom slot for handling selection change
    connect(ui->tab_artist->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));
}

pageartiste::~pageartiste()
{
    delete ui;

        delete proxyModel;
}

void pageartiste::on_pb_ajouter_clicked()
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

    QString nom_a = ui->nom_a->text();
    QString status_a = ui->status_a->text();
    QString oeuvresmaj_a = ui->oeuvresmaj_a->text();
    QString email_a = ui->email_a->text();
    QString styleart_a = ui->styleart_a ->text();

    if (ui->nom_a->text().isEmpty() || ui->status_a->text().isEmpty()
        || ui->oeuvresmaj_a->text().isEmpty() || ui->email_a->text().isEmpty()
        || ui->styleart_a->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    // Date Format Validation


    Artiste A(nom_a , status_a, oeuvresmaj_a, email_a, styleart_a);
    bool test = A.ajouter();
    if (test)
    {
        ui->tab_artist->setModel(A.afficher());

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
void pageartiste::on_pb_supprimer_clicked()
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

    Artiste A;

    QString nom_a = ui->nom_a->text();
    A.setnom_a(nom_a);

    bool exists = A.checkIfArtisteExists(nom_a);
    if (!exists) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("L'artiste n'a pas été trouvé dans la base de données.").arg(nom_a),
                              QMessageBox::Cancel);
        return;
    }

    bool test = A.supprimer(nom_a);
    if (test)
    {
        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Suppression effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();

        ui->tab_artist->setModel(A.afficher());
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


void pageartiste::on_pb_modifier_clicked()
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

    if (selectedArtisteRow == -1) {

        QMessageBox::warning(this, tr("Aucun employé sélectionné"),
                             tr("Veuillez sélectionner un employé à modifier."), QMessageBox::Ok);
        return;
    }

    QString nom_a = ui->nom_a->text();
    QString status_a = ui->status_a->text();
    QString oeuvresmaj_a = ui->oeuvresmaj_a->text();
    QString email_a = ui->email_a->text();
    QString styleart_a = ui->styleart_a->text();

    if (ui->nom_a->text().isEmpty() || ui->status_a->text().isEmpty()
        || ui->oeuvresmaj_a->text().isEmpty() || ui->email_a->text().isEmpty()
        || ui->styleart_a->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    QModelIndex index = ui->tab_artist->model()->index(selectedArtisteRow, 0); // Assuming the first column contains the primary key
    QString artist_id = ui->tab_artist->model()->data(index).toString();

    Artiste artistToUpdate(nom_a,status_a, oeuvresmaj_a, email_a, styleart_a);
    bool test = artistToUpdate.modifierE(artist_id);
    if (test)
    {
        ui->tab_artist->setModel(artistToUpdate.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Modification effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, &QMessageBox::finished, this, &pageartiste::handleMessageBoxResult);

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

void pageartiste::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel)
    {
        // User clicked Cancel, do something if needed
    }
}

void pageartiste::on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);

    // Get the selected row
    selectedArtisteRow = current.row();

    // Fill the line edits with the data from the selected row
    ui->nom_a->setText(ui->tab_artist->model()->index(selectedArtisteRow, 0).data().toString());
    ui->status_a->setText(ui->tab_artist->model()->index(selectedArtisteRow, 1).data().toString());
    ui->oeuvresmaj_a->setText(ui->tab_artist->model()->index(selectedArtisteRow, 2).data().toString());
    ui->email_a->setText(ui->tab_artist->model()->index(selectedArtisteRow, 3).data().toString());
    ui->styleart_a->setText(ui->tab_artist->model()->index(selectedArtisteRow, 4).data().toString());

}




void pageartiste::on_commandLinkButton_24_clicked()
{
    hide();
    Mainw = new MainWindow(this);
    Mainw->show();
}

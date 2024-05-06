#include "pageoeuvre.h"
#include "ui_pageoeuvre.h"
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
#include <fstream>
#include"recorder.h"
#include "qrcode.h"
using qrcodegen::QrCode;
using qrcodegen::QrSegment;
Pageoeuvre::Pageoeuvre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pageoeuvre),
    selectedOeuvreRow(-1),
    O(),
    proxyModel(new QSortFilterProxyModel())


{
    ui->setupUi(this);





    // Assuming afficher() returns a QSqlQueryModel
    QSqlQueryModel *model = O.afficher();
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

    ui->tab_oeuvre->setModel(standardModel);

    // Connect the clicked signal to the custom slot for handling selection change
    connect(ui->tab_oeuvre->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));
}

Pageoeuvre::~Pageoeuvre()
{
    delete ui;

        delete proxyModel;
}

void Pageoeuvre::on_pb_ajouter_clicked()
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

    QString nom_o= ui->nom_o->text();
    QString date_o = ui->date_o->text();
    QString prix_o = ui->prix_o->text();
    QString discription_o = ui->discription_o->text();

    if (ui->nom_o->text().isEmpty() || ui->date_o->text().isEmpty()
        || ui->prix_o->text().isEmpty() || ui->discription_o->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }


    QString nom_a = ui->nom_a->text();


      Oeuvre O(nom_o, date_o, prix_o.toInt(), discription_o);
      O.setnom_a(nom_a);

      bool test = O.ajouter();
    if (test)
    {
        ui->tab_oeuvre->setModel(O.afficher());

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
void Pageoeuvre::on_pb_supprimer_clicked()
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

    Oeuvre O;

    QString nom_o = ui->nom_o->text();
    O.setnom_o(nom_o);

    bool exists = O.checkIfOeuvreExists(nom_o);
    if (!exists) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("L'oeuvre n'a pas été trouvé dans la base de données.").arg(nom_o),
                              QMessageBox::Cancel);
        return;
    }

    bool test = O.supprimer(nom_o);
    if (test)
    {
        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Suppression effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();

        ui->tab_oeuvre->setModel(O.afficher());
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


void Pageoeuvre::on_pb_modifier_clicked()
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

    if (selectedOeuvreRow == -1) {

        QMessageBox::warning(this, tr("Aucun employé sélectionné"),
                             tr("Veuillez sélectionner un employé à modifier."), QMessageBox::Ok);
        return;
    }

    QString nom_o = ui->nom_o->text();
    QString date_o = ui->date_o->text();
    QString prix_o= ui->prix_o->text();
    QString discription_o = ui->discription_o->text();


    if (ui->nom_o->text().isEmpty() || ui->date_o->text().isEmpty()
        || ui->prix_o->text().isEmpty() || ui->discription_o->text().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    QModelIndex index = ui->tab_oeuvre->model()->index(selectedOeuvreRow, 0); // Assuming the first column contains the primary key
    QString Oeuvre_id = ui->tab_oeuvre->model()->data(index).toString();


    QString nom_a = ui->nom_a->text();

       Oeuvre oeuvreToUpdate(nom_o, date_o, prix_o.toInt(), discription_o);
       oeuvreToUpdate.setnom_a(nom_a);

       bool test = oeuvreToUpdate.modifierE(Oeuvre_id);
    if (test)
    {
        ui->tab_oeuvre->setModel(oeuvreToUpdate.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Modification effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, &QMessageBox::finished, this, &Pageoeuvre::handleMessageBoxResult);

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

void Pageoeuvre::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel)
    {
        // User clicked Cancel, do something if needed
    }
}

void Pageoeuvre::on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);

    // Get the selected row
    selectedOeuvreRow = current.row();

    // Fill the line edits with the data from the selected row
    ui->nom_o->setText(ui->tab_oeuvre->model()->index(selectedOeuvreRow, 0).data().toString());
    ui->date_o->setText(ui->tab_oeuvre->model()->index(selectedOeuvreRow, 1).data().toString());
    ui->prix_o->setText(ui->tab_oeuvre->model()->index(selectedOeuvreRow, 2).data().toString());
    ui->discription_o->setText(ui->tab_oeuvre->model()->index(selectedOeuvreRow, 3).data().toString());


}




void Pageoeuvre::on_commandLinkButton_24_clicked()
{
    hide();
    Mainw = new MainWindow(this);
    Mainw->show();
}

void Pageoeuvre::on_pushButton_clicked()
{
    recorder *rec = new recorder(this); // Passing 'this' as the parent will make MainWindow the parent of the recorder dialog
    rec->setWindowTitle("Enregistrer une image");
    rec->exec(); // Show the recorder dialog as a modal dialog
}

void Pageoeuvre::on_QR_clicked()
{
    // Check if a row is selected in the table
    if(ui->tab_oeuvre->currentIndex().row() == -1) {
        QMessageBox::information(nullptr, QObject::tr("QR"),
                                 QObject::tr("Veuillez choisir un identifiant.\n"
                                             "Cliquez sur Ok pour sortir."), QMessageBox::Ok);
    } else {
        // Retrieve the selected row index
        QModelIndex currentIndex = ui->tab_oeuvre->currentIndex();

        // Retrieve data from the selected row in the table
        QString nom_o = ui->tab_oeuvre->model()->index(currentIndex.row(), 0).data().toString();
        QString date_o = ui->tab_oeuvre->model()->index(currentIndex.row(), 1).data().toString();
        QString prix_o = ui->tab_oeuvre->model()->index(currentIndex.row(), 2).data().toString();
        QString discription_o = ui->tab_oeuvre->model()->index(currentIndex.row(), 3).data().toString();

        // Concatenate data into a single string (or use a suitable format)
        QString qrData = "Nom: " + nom_o + "\n"
                         + "Date: " + date_o + "\n"
                         + "Prix: " + prix_o + "\n"
                         + "Description: " + discription_o;

        // Use the data to generate the QR code
        const QrCode qr = QrCode::encodeText(qrData.toStdString().c_str(), QrCode::Ecc::LOW);

        // Save the QR code to a file
        std::ofstream myfile;
        myfile.open("qrcode.svg");
        myfile << qr.toSvgString(1);
        myfile.close();

        // Load the QR code image
        QPixmap pix("qrcode.svg");

        // Scale the image as needed
        QPixmap scaledPix = pix.scaled(200, 200);

        // Display the QR code image
        ui->QRCODE->setPixmap(scaledPix);

        // Update the UI with the selected row's data
        ui->nom_o->setText(nom_o);
        ui->date_o->setText(date_o);
        ui->prix_o->setText(prix_o);
        ui->discription_o->setText(discription_o);
    }
}

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
#include <QPainter>
#include <QBrush>
pageartiste::pageartiste(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pageartiste),
    A()


{
    ui->setupUi(this);
    ui->tab_artist->setModel(A.afficher());





/*
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
            this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));*/
}
void setartiste(Artiste ){}



void pageartiste::on_pb_ajouter_clicked()
{
    // Récupérer les valeurs saisies
    QString nom_a = ui->nom_a->text();
    QString status_a = ui->status_a->text();
    QString oeuvresmaj_a = ui->oeuvresmaj_a->text();
    QString email_a = ui->email_a->text();
    QString styleart_a = ui->styleart_a->text();





    // Ajouter les données dans la base de données
    Artiste A(0,nom_a,status_a,oeuvresmaj_a,email_a,styleart_a);
    bool test = A.ajouter();

    // Afficher un message en fonction du résultat de l'ajout
    if (test) {
        ui->tab_artist->setModel(A.afficher());
        ui->pb_ajouter->setText("Modification réussi !");
    } else {
        ui->pb_ajouter->setText("Modification a échoué !");
    }
}
void pageartiste::on_pb_supprimer_clicked()
{
    QModelIndexList selectedRows = ui->tab_artist->selectionModel()->selectedRows();
        if (selectedRows.isEmpty()) {
            QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                                  QObject::tr("Aucune ligne sélectionnée.\n"
                                              "Sélectionnez une ligne à supprimer."),
                                  QMessageBox::Cancel);
            return;
        }
        int ida = selectedRows.at(0).data().toInt();

        bool test =A.supprimer(ida);

        if (test) {
            ui->tab_artist->setModel(A.afficher());
            ui->pb_supprimer->setText("Modification réussi !");
        } else {
            ui->pb_supprimer->setText("Modification a échoué !");
        }

}

/*void pageartiste::on_pb_modifier_clicked()
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
    int ida = ui->tab_artist->model()->data(index).toInt(); // Corrected the variable name here
    Artiste artistToUpdate(ida, nom_a, status_a, oeuvresmaj_a, email_a, styleart_a);
    bool test = artistToUpdate.modifierE(ida);
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
}*/

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

void pageartiste::on_pushButton_clicked()
{
    // Call the afficher function to retrieve sorted data
        QSqlQueryModel* sortedModel = A.afficher1();

        // Set the sorted model to the table view
        ui->tab_artist->setModel(sortedModel);

}
pageartiste::~pageartiste()
{
    delete ui;


}

void pageartiste::on_pb_modifier_clicked()
{
    // Vérifier si une ligne est sélectionnée dans le QTableView
    QModelIndexList selectedRows = ui->tab_artist->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("Aucune ligne sélectionnée.\n"
                                          "Sélectionnez une ligne à modifier."),
                              QMessageBox::Cancel);
        return;
    }
    int row = selectedRows.at(0).row();

    // Récupérer les nouvelles valeurs des champs
    QString nom_a = ui->nom_a->text();
    QString status_a = ui->status_a->text();
    QString oeuvresmaj_a = ui->oeuvresmaj_a->text();
    QString email_a = ui->email_a->text();
    QString styleart_a = ui->styleart_a->text();


    // Récupérer l'ID à partir de la ligne sélectionnée dans le QTableView
    QModelIndex index = ui->tab_artist->model()->index(row, 0);
    int ida = ui->tab_artist->model()->data(index).toInt();

    // Créer un objet client avec les nouvelles valeurs et l'ID
    Artiste A(ida, nom_a,status_a,oeuvresmaj_a,email_a,styleart_a);

    // Appeler la fonction de modification pour mettre à jour les données dans la base de données
    bool test = A.modifierE(ida);
    if (test) {
        ui->tab_artist->setModel(A.afficher());
        ui->pb_modifier->setText("Modification réussi !");
    } else {
        ui->pb_modifier->setText("Modification a échoué !");
    }
}

void pageartiste::EXPORTER_clicked()
{
    QSqlQueryModel* model = A.afficher();

    if (model->rowCount() > 0) {
        ui->tab_artist->setModel(model);
        int exportStatus = A.exporterPDF(model);
        if (exportStatus == 0) {
            ui->EXPORTER->setText("Export réussi !");
        } else {
            ui->EXPORTER->setText("Échec de l'export !");
        }
    } else {
        ui->EXPORTER->setText("Échec de l'export !");
    }
    ui->EXPORTER->setText("Export réussi !");
}

void pageartiste::on_pushButton_5_clicked()
{
    QString searchName = ui->lineedit->text().trimmed(); // Get the text entered by the user
    qDebug() << "Searching for artist:" << searchName; // Output the search name to debug

    if (searchName.isEmpty()) {
        QMessageBox::information(this, tr("Empty Search"), tr("Please enter the name of the artist to search."));
        return;
    }

    // Get the model from the original table view
    QAbstractItemModel *originalModel = ui->tab_artist->model();
    if (!originalModel) {
        qDebug() << "No model set for the original table view";
        return;
    }

    // Create a new model for the destination table
    QStandardItemModel *destinationModel = new QStandardItemModel(0, originalModel->columnCount(), this);
    ui->tab_normes_rech->setModel(destinationModel);

    bool artistFound = false;

    // Iterate over each row in the original model
    for (int row = 0; row < originalModel->rowCount(); ++row) {
        // Get the artist's name in the current row
        QModelIndex index = originalModel->index(row, 0); // Assuming the nom_a column is the first column
        QString artistName = originalModel->data(index).toString();

        // Compare the artist's name with the search text
        if (artistName.contains(searchName, Qt::CaseInsensitive)) {
            // Artist found, copy the row data to the destination table
            QList<QStandardItem*> rowItems;
            for (int col = 0; col < originalModel->columnCount(); ++col) {
                QModelIndex index = originalModel->index(row, col);
                QString data = originalModel->data(index).toString();
                QStandardItem *item = new QStandardItem(data);
                rowItems.append(item);
            }
            destinationModel->appendRow(rowItems);

            artistFound = true;
        }
    }

    if (!artistFound) {
        // Artist not found, display a message or perform any other action
        QMessageBox::information(this, tr("Artist Not Found"), tr("The artist you searched for was not found."));
    }
}


void pageartiste::on_pushButton_2_clicked()
{
    // Step 1: Query the database to retrieve total price and count of art pieces sold by each artist
    QSqlQuery query;
    QString queryString = "SELECT NOM_A, SUM(PRIX_O) AS total_price, COUNT(*) AS art_count "
                          "FROM DEUVRE "
                          "GROUP BY NOM_A";
    if (!query.exec(queryString)) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }

    // Step 2: Calculate score for each artist and store them in a QMap
    QMap<QString, double> artistScores;
    while (query.next()) {
        QString artistName = query.value("NOM_A").toString();
        double totalPrice = query.value("total_price").toDouble();
        int artCount = query.value("art_count").toInt();

        // Calculate score based on total price and count of art pieces sold
        double score = totalPrice * artCount;

        // Store artist score in the QMap
        artistScores.insert(artistName, score);
    }

    // Step 3: Sort artists based on their scores and select the top 3
    QStringList topArtists;
    int count = 0;
    for (auto it = artistScores.begin(); it != artistScores.end() && count < 3; ++it) {
        topArtists << it.key();
        count++;
    }

    // Step 4: Display the names of the top 3 artists in textEdit
    ui->textEdit->clear();
    ui->textEdit->setText(topArtists.join("\n"));
}


void pageartiste::on_stat_clicked()
{
    // Step 1: Query the database to retrieve the count of each unique STYLEART_A
        QSqlQuery query;
        QString queryString = "SELECT STYLEART_A, COUNT(*) AS style_count "
                              "FROM ARTISTE "
                              "GROUP BY STYLEART_A "
                              "ORDER BY style_count DESC";

        if (!query.exec(queryString)) {
            qDebug() << "Error executing query:" << query.lastError().text();
            return;
        }

        // Step 2: Select the top 3 STYLEART_A values
        QStringList topStyles;
        int count = 0;
        while (query.next() && count < 3) {
            QString style = query.value("STYLEART_A").toString();
            topStyles << style;
            count++;
        }

        // Step 3: Display the top 3 STYLEART_A values in textEdit_2
        ui->textEdit_2->clear();
        ui->textEdit_2->setText(topStyles.join("\n"));
}

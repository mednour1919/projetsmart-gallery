#include "pageevenement.h"
#include "ui_pageevenement.h"
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
#include <QPainter>
#include <QFileDialog>
#include <QtCharts>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include <cstdlib>
#include <ctime>
#include <QFile>
#include "smtp.h"
pageevenement::pageevenement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::pageevenement),
    selectedEventRow(-1),
    E(),
    proxyModel(new QSortFilterProxyModel()),
  eventProxyModel(new QSortFilterProxyModel()),
     standardModel(new QStandardItemModel())

{
    ui->setupUi(this);

    ui->nb_e->setValidator(new QIntValidator(0, 99999999, this));



    // Assuming afficher() returns a QSqlQueryModel
    QSqlQueryModel *model = E.afficher();
      proxyModel->setSourceModel(model);
      eventProxyModel = new QSortFilterProxyModel(this);
      eventProxyModel->setSourceModel(E.afficher());
      ui->tab_events->setModel(eventProxyModel);

      // Connect the textChanged signal to the slot for filtering

       connect(ui->refrech, SIGNAL(clicked()), this, SLOT(on_refrech_clicked()));
       connect(ui->sortAscButton, SIGNAL(clicked()), this, SLOT(on_sortAscButton_clicked()));
       connect(ui->sortDescButton, SIGNAL(clicked()), this, SLOT(on_sortDescButton_clicked()));
       connect(ui->tab_client->selectionModel(), SIGNAL(currentRowChanged(QModelIndex,QModelIndex)), this, SLOT(on_tabArtisteSelectionChanged(QModelIndex,QModelIndex)));

         // Load data for tab_client
         loadclientData();
          loadHighBudgetClients();
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

    ui->tab_events->setModel(standardModel);

    // Connect the clicked signal to the custom slot for handling selection change
    connect(ui->tab_events->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
            this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));
}

pageevenement::~pageevenement()
{
    delete ui;

        delete proxyModel;
}
void pageevenement::loadclientData()
{
    QSqlQueryModel *artisteModel = E.retrieveCLIENTData();
    if (artisteModel) {
        ui->tab_client->setModel(artisteModel);
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to load CLIENT data."));
    }
}
void pageevenement::loadHighBudgetClients()
{
    // Assuming E.retrieveHighBudgetClients() retrieves clients with budget greater than 2000
    QSqlQueryModel *highBudgetClientsModel = E.retrieveHighBudgetClients();
    if (highBudgetClientsModel) {
        ui->tab_client->setModel(highBudgetClientsModel);
    } else {
        QMessageBox::critical(this, tr("Error"), tr("Failed to load high budget clients."));
    }
}

void pageevenement::on_pb_ajouter_clicked()
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

    QString titre_e = ui->titre_e->text();
    QString dated_e = ui->dated_e->text();
    QString datef_e = ui->datef_e->text();
    int nb_e = ui->nb_e->text().toInt();
    QString location_e = ui->location_e->currentText();

    if (ui->titre_e->text().isEmpty() || ui->dated_e->text().isEmpty() || ui->datef_e->text().isEmpty()
        || ui->nb_e->text().isEmpty() || ui->location_e->currentText().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    QString nom_a = ui->nom_a->text();
    Event E(titre_e, dated_e, datef_e, nb_e, location_e);
    E.setnom_a(nom_a);
    bool test = E.ajouter();
    if (test)
    {
        ui->tab_events->setModel(E.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Ajout effectué. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();

        // Send notification
        QTime time = ui->timeEdit->time();
        int sec = QTime(0, 0).msecsTo(time);
        QString message = "Evenement Ajouter"; // Set the message directly here

        QSystemTrayIcon *trayIcon = new QSystemTrayIcon(this);
        trayIcon->setIcon(QIcon("C:/icon.png"));
        trayIcon->setToolTip("Application");
        QTimer::singleShot(sec, trayIcon, [trayIcon,message] {
            trayIcon->showMessage("Reservation", message, QSystemTrayIcon::Information, 5000);
        });

        connect(trayIcon, &QSystemTrayIcon::messageClicked, trayIcon, &QSystemTrayIcon::hide);
        connect(trayIcon, &QSystemTrayIcon::activated, trayIcon, &QSystemTrayIcon::hide);
        trayIcon->show();


        connect(trayIcon, &QSystemTrayIcon::messageClicked, trayIcon, &QSystemTrayIcon::hide);
        connect(trayIcon, &QSystemTrayIcon::activated, trayIcon, &QSystemTrayIcon::hide);
        trayIcon->show();
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


void pageevenement::on_pb_supprimer_clicked()
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

    Event E;

    QString titre_e = ui->titre_e->text();
    E.settitre_e(titre_e);

    bool exists = E.checkIfeventExists(titre_e);
    if (!exists) {
        QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                              QObject::tr("L'event n'a pas été trouvé dans la base de données.").arg(titre_e),
                              QMessageBox::Cancel);
        return;
    }

    bool test = E.supprimer(titre_e);
    if (test)
    {
        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Suppression effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();

        ui->tab_events->setModel(E.afficher());
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


void pageevenement::on_pb_modifier_clicked()
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

    if (selectedEventRow == -1) {

        QMessageBox::warning(this, tr("Aucun employé sélectionné"),
                             tr("Veuillez sélectionner un event à modifier."), QMessageBox::Ok);
        return;
    }

    QString titre_e = ui->titre_e->text();
    QString dated_e = ui->dated_e->text();
    QString datef_e = ui->datef_e->text();
    int nb_e = ui->nb_e->text().toInt();
    QString location_e = ui->location_e->currentText();

    if (ui->titre_e->text().isEmpty() ||  ui->dated_e->text().isEmpty() || ui->datef_e->text().isEmpty()
        || ui->nb_e->text().isEmpty() || ui->location_e->currentText().isEmpty()) {
        QMessageBox::warning(this, tr("Champs manquants"),
                             tr("Veuillez remplir tous les champs."), QMessageBox::Ok);
        return;
    }

    QModelIndex index = ui->tab_events->model()->index(selectedEventRow, 0);
    QString event_id = ui->tab_events->model()->data(index).toString();

    QString nom_a = ui->nom_a->text();
    Event eventToUpdate(titre_e, dated_e, datef_e, nb_e, location_e);
    E.setnom_a(nom_a);
    bool test = eventToUpdate.modifierE(event_id);
    if (test)
    {
        ui->tab_events->setModel(eventToUpdate.afficher());

        QMessageBox msgBox(QMessageBox::Information, QObject::tr("OK"),
                           QObject::tr("Modification effectuée. \nClick Cancel to exit."), QMessageBox::Cancel, this);

        // Connect the finished signal to a custom slot
        connect(&msgBox, &QMessageBox::finished, this, &pageevenement::handleMessageBoxResult);

        msgBox.exec();
    }
    else
    {
        QMessageBox msgBox(QMessageBox::Critical, QObject::tr("Erreur"),
                           QObject::tr("event non trouvé ou modification non effectuée.\nClick Cancel to exit."), QMessageBox::Cancel, this);


        connect(&msgBox, SIGNAL(finished(int)), this, SLOT(handleMessageBoxResult(int)));

        msgBox.exec();
    }
}

void pageevenement::handleMessageBoxResult(int result)
{
    if (result == QMessageBox::Cancel)
    {

    }
}

void pageevenement::on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);


    selectedEventRow = current.row();


    ui->titre_e->setText(ui->tab_events->model()->index(selectedEventRow, 0).data().toString());
    ui->dated_e->setText(ui->tab_events->model()->index(selectedEventRow, 1).data().toString());
    ui->datef_e->setText(ui->tab_events->model()->index(selectedEventRow, 2).data().toString());
    ui->nb_e->setText(ui->tab_events->model()->index(selectedEventRow, 3).data().toString());
    ui->location_e->setCurrentText(ui->tab_events->model()->index(selectedEventRow, 4).data().toString());

}




void pageevenement::on_commandLinkButton_24_clicked()
{
    hide();
    Mainw = new MainWindow(this);
    Mainw->show();
}


void pageevenement::on_eventSearchLineEdit_textChanged(const QString &text)
{

    if (eventProxyModel != nullptr)
    {

        eventProxyModel->setFilterCaseSensitivity(Qt::CaseInsensitive);


        eventProxyModel->setFilterKeyColumn(0);


        eventProxyModel->setFilterRegExp(text);

        qDebug() << "Filtering with text:" << text;
    }
}

void pageevenement::statistics() {
    QSqlQuery query;
    qreal tot = 0;
    QMap<QString, qreal> locationCounts;


    if (!query.exec("SELECT LOCATION_E, COUNT(*) FROM EVENEMENT GROUP BY LOCATION_E")) {
        qDebug() << "Error executing query:" << query.lastError().text();
        return;
    }


    while (query.next()) {
        QString location = query.value(0).toString();
        qreal count = query.value(1).toDouble();
        locationCounts.insert(location, count);
        tot += count;
    }


    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.35);


    for (auto it = locationCounts.begin(); it != locationCounts.end(); ++it) {
        qreal percentage = (tot != 0) ? it.value() / tot : 0;
        series->append(it.key(), percentage);
    }


    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setTitle("Répartition par emplacement");


    QChartView *chartview = new QChartView(chart, ui->lab_chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setMinimumSize(600, 600);
    chartview->show();
}

void pageevenement::on_pushButton_4_clicked()
{


        QDialog *dialog = new QDialog(this);
        QVBoxLayout *layout = new QVBoxLayout(dialog);


        statistics();



        layout->addWidget(ui->lab_chart);


        dialog->setWindowTitle("Location Statistics");
        dialog->resize(800, 600);


        dialog->exec();

}

void pageevenement::on_refrech_clicked()
{

    // Clear the line edits
      ui->titre_e->clear();
      ui->dated_e->clear();
      ui->datef_e->clear();
      ui->nb_e->clear();
      ui->location_e->setCurrentIndex(-1);

      // Reset selectedEventRow to -1
      selectedEventRow = -1;

      // Optionally, re-enable the signal-slot connection for handling selection changes
      connect(ui->tab_events->selectionModel(), SIGNAL(currentRowChanged(QModelIndex, QModelIndex)),
              this, SLOT(on_tableViewSelectionChanged(QModelIndex, QModelIndex)));
  }
void pageevenement::on_sortAscButton_clicked()
{
    QSqlQueryModel *sortedModel = E.sortByParticipantsAsc();
    ui->tab_events->setModel(sortedModel);
}

void pageevenement::on_sortDescButton_clicked()
{
    QSqlQueryModel *sortedModel = E.sortByParticipantsDesc();
    ui->tab_events->setModel(sortedModel);
}
void pageevenement::on_radioButton_clicked()
{
    // Clear the existing proxy model
    delete proxyModel;
    proxyModel = nullptr;

    // Create a new proxy model
    proxyModel = new QSortFilterProxyModel(this);
    proxyModel->setSourceModel(E.afficher());

    // Set the filter case sensitivity based on the radio button state
    Qt::CaseSensitivity caseSensitivity = ui->radioButton->isChecked() ?
                                           Qt::CaseInsensitive : Qt::CaseSensitive;
    proxyModel->setFilterCaseSensitivity(caseSensitivity);

    // Set the filter key column for the "titre_e" column (assuming it's the first column)
    proxyModel->setFilterKeyColumn(0);

    // Set the proxy model for the table view
    ui->tab_events->setModel(proxyModel);
}



void pageevenement::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
    // Update the filter based on the contents of the line edit
    if (proxyModel != nullptr)
    {
        proxyModel->setFilterRegExp(ui->lineEdit->text());
    }
}

void pageevenement::on_send_clicked()
{

    QString to = ui->rcpt->text();

    QString message = ui->msg->toPlainText();

   QString subject = "event";
    sendMail(to, subject, message);
}

void pageevenement::sendMail(const QString &to, const QString &subject, const QString &message)
{
    // Assuming you have access to the necessary variables for SMTP configuration
    QString user = "nourhichri299@gmail.com";
    QString pass = "anazupawurqexojz";
    QString host = "smtp.gmail.com";
    int port = 465; // Use the appropriate port for your SMTP server
    int timeout = 30000; // Timeout value in milliseconds

    QString from = "nourhichri299@gmail.com"; // Update sender email

    // Create an instance of the Smtp class
    Smtp *smtp = new Smtp(user, pass, host, port, timeout);

    // Send the email
    smtp->sendMail(from, to, subject, message);
}
void pageevenement::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP rdv" ), tr( "Message sent!\n\n" ) );
}

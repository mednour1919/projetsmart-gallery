#ifndef PAGEEVENEMENT_H
#define PAGEEVENEMENT_H
class event;

#include <QMainWindow>
#include "oeuvre.h"
#include "arduino.h"
#include <QTimer>
#include <QTimer>
#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "event.h"
#include "mainwindow.h"
#include <QStandardItemModel>
class oeuvre;
class MainWindow;

class pageevenement;
class QSortFilterProxyModel;
namespace Ui {
class pageevenement;
}

class pageevenement : public QDialog
{
    Q_OBJECT

public:
    explicit pageevenement(QWidget *parent = nullptr);
    ~pageevenement();
    QSqlQueryModel *sortByParticipantsAsc();
       QSqlQueryModel *sortByParticipantsDesc();
private slots:
    void on_pb_supprimer_clicked();
  void on_tabOeuvreSelectionChanged(const QModelIndex &current, const QModelIndex &previous);
    void on_pb_modifier_clicked();

    void on_pb_ajouter_clicked();


    void handleMessageBoxResult(int result);


    void on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous);




    void on_commandLinkButton_24_clicked();


void on_eventSearchLineEdit_textChanged(const QString &text);

void on_pushB_clicked();
void statistics();
void on_pushButton_4_clicked();

void on_refrech_clicked();
void on_sortAscButton_clicked();
void on_sortDescButton_clicked();
void on_radioButton_clicked();
void on_lineEdit_cursorPositionChanged(int arg1, int arg2);
void on_send_clicked();
void sendMail(const QString &to, const QString &subject, const QString &message);
void mailSent(QString status);
void loadclientData();
void loadHighBudgetClients();

void on_pushc1_clicked();
void delayedButtonClick();
void on_pushc2_clicked();
void readData();
private:
    Ui::pageevenement *ui;
    MainWindow * Mainw;
    Event E ;
    int selectedEventRow;
    QSortFilterProxyModel *proxyModel;
    QSortFilterProxyModel *eventProxyModel;
    QStandardItemModel *standardModel;
 Oeuvre oeuvre;
 QByteArray data; // variable contenant les données reçues
 QString selectedOeuvreId;
 Arduino A;
  QTimer *delayedClickTimer;
};


#endif // PAGEEVENEMENT_H


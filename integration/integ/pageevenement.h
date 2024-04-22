#ifndef PAGEEVENEMENT_H
#define PAGEEVENEMENT_H
class event;

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

    void on_pb_modifier_clicked();

    void on_pb_ajouter_clicked();


    void handleMessageBoxResult(int result);


    void on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous);




    void on_commandLinkButton_24_clicked();


void on_eventSearchLineEdit_textChanged(const QString &text);


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

private:
    Ui::pageevenement *ui;
    MainWindow * Mainw;
    Event E ;
    int selectedEventRow;
    QSortFilterProxyModel *proxyModel;
    QSortFilterProxyModel *eventProxyModel;
    QStandardItemModel *standardModel;
};


#endif // PAGEEVENEMENT_H


#ifndef PAGECLIENT_H
#define PAGECLIENT_H
class Client;
#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "client.h"
#include "mainwindow.h"
class MainWindow;

class pageclient;
class QSortFilterProxyModel;
namespace Ui {
class pageclient;
}

class pageclient : public QDialog
{
    Q_OBJECT

public:
    explicit pageclient(QWidget *parent = nullptr);
    ~pageclient();

private slots:
    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_ajouter_clicked();


    void handleMessageBoxResult(int result);


    void on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous);



    void on_commandLinkButton_24_clicked();

private:
    Ui::pageclient *ui;
    MainWindow * Mainw;
    Client C ;
    int selectedClientRow;
    QSortFilterProxyModel *proxyModel;
};


#endif // PAGECLIENT_H

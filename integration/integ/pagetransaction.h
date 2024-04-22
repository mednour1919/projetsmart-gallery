#ifndef PAGETRANSACTION_H
#define PAGETRANSACTION_H
class Transaction;

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "transaction.h"
#include "mainwindow.h"
class MainWindow;

class pagetransaction;
class QSortFilterProxyModel;
namespace Ui {
class pagetransaction;
}

class pagetransaction : public QDialog
{
    Q_OBJECT

public:
    explicit pagetransaction(QWidget *parent = nullptr);
    ~pagetransaction();

private slots:
    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_ajouter_clicked();


    void handleMessageBoxResult(int result);


    void on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous);




    void on_commandLinkButton_24_clicked();

private:
    Ui::pagetransaction *ui;
    MainWindow * Mainw;
    Transaction T ;
    int selectedTransRow;
    QSortFilterProxyModel *proxyModel;
};


#endif // PAGETRANSACTION_H


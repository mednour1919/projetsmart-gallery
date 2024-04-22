#ifndef PAGEPERSONNEL_H
#define PAGEPERSONNEL_H

class Pers;
#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "pers.h"
#include "mainwindow.h"
class MainWindow;

class pageclient;
class QSortFilterProxyModel;
namespace Ui {
class pagepersonnel;
}

class pagepersonnel : public QDialog
{
    Q_OBJECT

public:
    explicit pagepersonnel(QWidget *parent = nullptr);
    ~pagepersonnel();

private slots:
    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_ajouter_clicked();


    void handleMessageBoxResult(int result);


    void on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous);




    void on_commandLinkButton_24_clicked();

private:
    Ui::pagepersonnel *ui;
    MainWindow * Mainw;
    Pers P;
    int selectedPersRow;
    QSortFilterProxyModel *proxyModel;
};


#endif // PAGEPERSONNEL_H

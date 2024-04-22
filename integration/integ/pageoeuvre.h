#ifndef PAGEOEUVRE_H
#define PAGEOEUVRE_H
#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "oeuvre.h"
#include "mainwindow.h"
class MainWindow;

class pageevenement;
class QSortFilterProxyModel;
namespace Ui {
class Pageoeuvre;
}

class Pageoeuvre : public QDialog
{
    Q_OBJECT

public:
    explicit Pageoeuvre(QWidget *parent = nullptr);
    ~Pageoeuvre();
    QSqlQueryModel *sortBySalaireAsc();
    QSqlQueryModel *sortBySalaireDesc();

private slots:
    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_ajouter_clicked();


    void handleMessageBoxResult(int result);


    void on_tableViewSelectionChanged(const QModelIndex &current, const QModelIndex &previous);




    void on_commandLinkButton_24_clicked();

private:
    Ui::Pageoeuvre *ui;
    MainWindow * Mainw;
    Oeuvre O ;
    int selectedOeuvreRow;
    QSortFilterProxyModel *proxyModel;
};


#endif// PAGEOEUVRE_H




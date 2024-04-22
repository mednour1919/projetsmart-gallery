#ifndef PAGEARTISTE_H
#define PAGEARTISTE_H
class Artiste;

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include <QtDebug>
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "artiste.h"
#include "mainwindow.h"
class MainWindow;

class pageevenement;
class QSortFilterProxyModel;
namespace Ui {
class pageartiste;
}

class pageartiste : public QDialog
{
    Q_OBJECT

public:
    explicit pageartiste(QWidget *parent = nullptr);
    ~pageartiste();
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
    Ui::pageartiste *ui;
    MainWindow * Mainw;
    Artiste A ;
    int selectedArtisteRow;
    QSortFilterProxyModel *proxyModel;
};


#endif // PAGEARTISTE_H

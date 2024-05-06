#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "pageevenement.h"
#include "pagetransaction.h"
#include "pageoeuvre.h"
#include "pageartiste.h"
#include "pageclient.h"
#include "pagepersonnel.h"

#include <QMainWindow>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class pageevenement;
class pagepersonnel;
class pageclient;
class pageartiste;
class pagetransaction;
class Pageoeuvre;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();



    void on_pushButton_5_clicked();

    void on_pushButton_clicked();


private:
    Ui::MainWindow *ui;
    pageevenement *Pageevenement;
    pagetransaction *Pagetransaction;
    Pageoeuvre *pageoeuvre;
    pageartiste *Pageartiste;
    pageclient *Pageclient;
    pagepersonnel *Pagepersonnel;

    QTimer *timer;
};

#endif // MAINWINDOW_H

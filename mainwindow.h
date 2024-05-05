#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include "transactions.h"
#include "QSqlTableModel"
#include <QtWidgets/QStackedWidget>
#include <QDebug>
#include <QProcess>
#include"arduino.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_valider_clicked();

    void on_quitter_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_valider_2_clicked();

    void on_quitter_2_clicked();

    void on_suprimer_clicked();

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_updatetableView_doubleClicked(const QModelIndex &index);

    void on_comboBox_activated(int index);

    void on_searchTextBox_textChanged(const QString &arg1);

   // void on_label_13_objectNameChanged(const QString &objectName);

    // void on_label_13_windowIconChanged(const QIcon &icon);

    void on_stackedWidget_currentChanged(int arg1);

    void on_pushButton_5_clicked();

    void update_label();

    void on_PLUS_clicked();

    void on_MOINS_clicked();

    void on_ON_clicked();

    void on_OFF_clicked();

    void on_pushButton_6_clicked();

    void on_reserver_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;
    transactions Tr;
    int id_transaction;
    QStackedWidget * stackedWidget;
    QSqlTableModel *model;
    QProcess *process ;
    QByteArray data;
    Arduino A;
};
#endif // MAINWINDOW_H

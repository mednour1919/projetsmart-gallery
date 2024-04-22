/********************************************************************************
** Form generated from reading UI file 'pageevenement.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEEVENEMENT_H
#define UI_PAGEEVENEMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageevenement
{
public:
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *tab_events;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *titre_e;
    QLineEdit *nb_e;
    QPushButton *pb_ajouter;
    QPushButton *pb_modifier;
    QPushButton *pb_supprimer;
    QLineEdit *dated_e;
    QLineEdit *datef_e;
    QLabel *label_9;
    QLineEdit *nom_a;
    QRadioButton *radioButton;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QPushButton *sortAscButton;
    QPushButton *sortDescButton;
    QComboBox *location_e;
    QPushButton *pushButton_4;
    QLabel *lab_chart;
    QTimeEdit *timeEdit;
    QPushButton *refrech;
    QWidget *tab_2;
    QLabel *label_56;
    QLineEdit *rcpt;
    QLabel *label_53;
    QPlainTextEdit *msg;
    QPushButton *send;
    QTableView *tab_client;
    QCommandLinkButton *commandLinkButton_24;

    void setupUi(QDialog *pageevenement)
    {
        if (pageevenement->objectName().isEmpty())
            pageevenement->setObjectName(QStringLiteral("pageevenement"));
        pageevenement->resize(1311, 746);
        label = new QLabel(pageevenement);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, -50, 1451, 811));
        label->setStyleSheet(QStringLiteral("border-image: url(:/img/img/R.jpg);"));
        tabWidget = new QTabWidget(pageevenement);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(100, 70, 1211, 671));
        tabWidget->setStyleSheet(QLatin1String("/* styles.qss */\n"
"\n"
"* {\n"
"    font-family: \"Playfair Display\", serif; /* Fallback to generic serif font if Playfair Display is not available */\n"
"    color: black;\n"
"}\n"
"\n"
"/* Style for QGroupBox */\n"
"QGroupBox {\n"
"    border: 2px solid #e67e22; /* Change to a bright orange color */\n"
"    border-radius: 5px;\n"
"    padding: 10px;\n"
"    color: white; /* Set text color inside group box */\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"}\n"
"\n"
"/* Style for QLineEdit (input box) */\n"
"QLineEdit {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Style for QComboBox */\n"
"QComboBox {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a"
                        " darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: white;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    color: black;\n"
"}\n"
"\n"
"/* Style for QDateEdit */\n"
"QDateEdit {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Style for QLabel */\n"
"QLabel {\n"
"    color: #e67e22; /* Change to a bright orange color */\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    margin: 5px;\n"
"}\n"
"\n"
"/* Style for QPushButton */\n"
"QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}\n"
"\n"
"/* Additional styling"
                        " for better appearance */\n"
"QPushButton:hover {\n"
"    background-color: #d35400; /* Darker orange color on hover */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #a04000; /* Even darker orange color on press */\n"
"}\n"
"\n"
"/* Style for QTableView */\n"
"QTableView {\n"
"    background-color: rgba(255, 255, 255, 0.8); /* Slightly transparent white background */\n"
"    border: 5px solid #e67e22; /* Creative thick orange border */\n"
"    border-radius: 15px; /* Rounded corners for a more creative look */\n"
"    selection-background-color: #e67e22; /* Change to a bright orange color */\n"
"}\n"
"\n"
"/* Style for QHeaderView */\n"
"QHeaderView::section {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    color: white;\n"
"    padding: 5px;\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"/* Style for QTableWidgetItem */\n"
"QTableView QTableWidget::item {\n"
"    backgr"
                        "ound-color: rgba(255, 255, 255, 0.8); /* Slightly transparent white background */\n"
"    color: black;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"QTableView QTableWidget::item:selected {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView QTableWidget::item:alternate {\n"
"    background-color: #ecf0f1;\n"
"    color: black;\n"
"}\n"
"\n"
"/* Style for QTabWidget */\n"
"QTabWidget {\n"
"    background-color: #ffffff; /* Set background color for the tab widget */\n"
"}\n"
"\n"
"/* Style for QTabBar */\n"
"QTabBar {\n"
"    background-color: #e67e22; /* Set the background color for the tab bar */\n"
"}\n"
"\n"
"/* Style for selected tab */\n"
"QTabBar::tab:selected {\n"
"    background-color: #d35400; /* Darker orange color for the selected tab */\n"
"    color: white; /* Text color for the selected tab */\n"
"    border: 2px solid #a04000; /* Border style for the selected tab */\n"
"    border-bottom: none; /* Remove bottom b"
                        "order to create a top border effect */\n"
"}\n"
"\n"
"/* Style for unselected tabs */\n"
"QTabBar::tab {\n"
"    background-color: #e67e22; /* Default background color for tabs */\n"
"    color: white; /* Default text color for tabs */\n"
"    border: 2px solid #d35400; /* Default border style for tabs */\n"
"    border-bottom: none; /* Remove bottom border to create a top border effect */\n"
"}\n"
"\n"
"/* Style for unselected tabs on hover */\n"
"QTabBar::tab:hover {\n"
"    background-color: #d35400; /* Darker orange color on hover for unselected tabs */\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tab_events = new QTableView(tab);
        tab_events->setObjectName(QStringLiteral("tab_events"));
        tab_events->setGeometry(QRect(460, 90, 581, 451));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 140, 141, 61));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 190, 181, 51));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 260, 131, 51));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 330, 151, 41));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 380, 131, 51));
        titre_e = new QLineEdit(tab);
        titre_e->setObjectName(QStringLiteral("titre_e"));
        titre_e->setGeometry(QRect(200, 160, 211, 22));
        nb_e = new QLineEdit(tab);
        nb_e->setObjectName(QStringLiteral("nb_e"));
        nb_e->setGeometry(QRect(210, 340, 211, 22));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(50, 500, 102, 28));
        pb_modifier = new QPushButton(tab);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(180, 500, 102, 28));
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(340, 500, 102, 28));
        dated_e = new QLineEdit(tab);
        dated_e->setObjectName(QStringLiteral("dated_e"));
        dated_e->setGeometry(QRect(210, 210, 191, 22));
        datef_e = new QLineEdit(tab);
        datef_e->setObjectName(QStringLiteral("datef_e"));
        datef_e->setGeometry(QRect(200, 270, 201, 22));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 90, 121, 41));
        nom_a = new QLineEdit(tab);
        nom_a->setObjectName(QStringLiteral("nom_a"));
        nom_a->setGeometry(QRect(200, 110, 221, 22));
        radioButton = new QRadioButton(tab);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(570, 20, 71, 20));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(420, 10, 101, 31));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(660, 20, 221, 22));
        sortAscButton = new QPushButton(tab);
        sortAscButton->setObjectName(QStringLiteral("sortAscButton"));
        sortAscButton->setGeometry(QRect(460, 70, 291, 28));
        sortDescButton = new QPushButton(tab);
        sortDescButton->setObjectName(QStringLiteral("sortDescButton"));
        sortDescButton->setGeometry(QRect(752, 70, 291, 28));
        location_e = new QComboBox(tab);
        location_e->setObjectName(QStringLiteral("location_e"));
        location_e->setGeometry(QRect(200, 400, 211, 22));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1080, 440, 93, 28));
        lab_chart = new QLabel(tab);
        lab_chart->setObjectName(QStringLiteral("lab_chart"));
        lab_chart->setGeometry(QRect(410, 160, 641, 301));
        timeEdit = new QTimeEdit(tab);
        timeEdit->setObjectName(QStringLiteral("timeEdit"));
        timeEdit->setGeometry(QRect(530, 440, 118, 22));
        refrech = new QPushButton(tab);
        refrech->setObjectName(QStringLiteral("refrech"));
        refrech->setGeometry(QRect(1010, 20, 75, 23));
        tabWidget->addTab(tab, QString());
        timeEdit->raise();
        lab_chart->raise();
        tab_events->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        label_5->raise();
        label_6->raise();
        titre_e->raise();
        nb_e->raise();
        pb_ajouter->raise();
        pb_modifier->raise();
        pb_supprimer->raise();
        dated_e->raise();
        datef_e->raise();
        label_9->raise();
        nom_a->raise();
        radioButton->raise();
        label_7->raise();
        lineEdit->raise();
        sortAscButton->raise();
        sortDescButton->raise();
        location_e->raise();
        pushButton_4->raise();
        refrech->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_56 = new QLabel(tab_2);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setGeometry(QRect(30, 220, 171, 31));
        rcpt = new QLineEdit(tab_2);
        rcpt->setObjectName(QStringLiteral("rcpt"));
        rcpt->setGeometry(QRect(300, 100, 501, 30));
        rcpt->setStyleSheet(QStringLiteral(""));
        label_53 = new QLabel(tab_2);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setGeometry(QRect(60, 100, 191, 31));
        msg = new QPlainTextEdit(tab_2);
        msg->setObjectName(QStringLiteral("msg"));
        msg->setGeometry(QRect(290, 180, 511, 150));
        send = new QPushButton(tab_2);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(510, 470, 93, 28));
        tab_client = new QTableView(tab_2);
        tab_client->setObjectName(QStringLiteral("tab_client"));
        tab_client->setGeometry(QRect(850, 50, 341, 481));
        tabWidget->addTab(tab_2, QString());
        commandLinkButton_24 = new QCommandLinkButton(pageevenement);
        commandLinkButton_24->setObjectName(QStringLiteral("commandLinkButton_24"));
        commandLinkButton_24->setGeometry(QRect(1040, 30, 91, 41));
        commandLinkButton_24->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));

        retranslateUi(pageevenement);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(pageevenement);
    } // setupUi

    void retranslateUi(QDialog *pageevenement)
    {
        pageevenement->setWindowTitle(QApplication::translate("pageevenement", "Dialog", Q_NULLPTR));
        label->setText(QString());
        label_2->setText(QApplication::translate("pageevenement", "Titre", Q_NULLPTR));
        label_3->setText(QApplication::translate("pageevenement", "Date de debut", Q_NULLPTR));
        label_4->setText(QApplication::translate("pageevenement", "Date de fin", Q_NULLPTR));
        label_5->setText(QApplication::translate("pageevenement", "Nombre d'invitation", Q_NULLPTR));
        label_6->setText(QApplication::translate("pageevenement", "Location", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("pageevenement", "Ajouter", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("pageevenement", "Modifier", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("pageevenement", "Supprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("pageevenement", "Nom article", Q_NULLPTR));
        radioButton->setText(QApplication::translate("pageevenement", "Titre", Q_NULLPTR));
        label_7->setText(QApplication::translate("pageevenement", "Recherche", Q_NULLPTR));
        sortAscButton->setText(QApplication::translate("pageevenement", "ASC", Q_NULLPTR));
        sortDescButton->setText(QApplication::translate("pageevenement", "DESC", Q_NULLPTR));
        location_e->clear();
        location_e->insertItems(0, QStringList()
         << QApplication::translate("pageevenement", "location1", Q_NULLPTR)
         << QApplication::translate("pageevenement", "location2", Q_NULLPTR)
         << QApplication::translate("pageevenement", "location3", Q_NULLPTR)
        );
        pushButton_4->setText(QApplication::translate("pageevenement", "Locations", Q_NULLPTR));
        lab_chart->setText(QString());
        refrech->setText(QApplication::translate("pageevenement", "Refrech", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pageevenement", "Ajouter", Q_NULLPTR));
        label_56->setText(QApplication::translate("pageevenement", "Message:", Q_NULLPTR));
        label_53->setText(QApplication::translate("pageevenement", "Email", Q_NULLPTR));
        send->setText(QApplication::translate("pageevenement", "Envoyer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("pageevenement", "Page", Q_NULLPTR));
        commandLinkButton_24->setText(QApplication::translate("pageevenement", "retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pageevenement: public Ui_pageevenement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEEVENEMENT_H

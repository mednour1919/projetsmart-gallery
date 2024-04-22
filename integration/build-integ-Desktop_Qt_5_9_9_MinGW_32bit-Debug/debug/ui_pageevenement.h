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
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
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
    QLabel *label_7;
    QPushButton *pb_modifier;
    QPushButton *pb_supprimer;
    QLineEdit *location_e;
    QLineEdit *dated_e;
    QLineEdit *datef_e;
    QLabel *label_9;
    QLineEdit *nom_a;
    QWidget *tab_4;
    QTableView *tab_events_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *tab_2;
    QTableView *tableView_2;
    QPushButton *pushButton;
    QLabel *label1;
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
        tabWidget->setGeometry(QRect(100, 70, 1091, 571));
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
        tab_events->setGeometry(QRect(490, 10, 581, 451));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 80, 141, 61));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 130, 181, 51));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(70, 200, 131, 51));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 270, 151, 41));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 320, 131, 51));
        titre_e = new QLineEdit(tab);
        titre_e->setObjectName(QStringLiteral("titre_e"));
        titre_e->setGeometry(QRect(230, 100, 211, 22));
        nb_e = new QLineEdit(tab);
        nb_e->setObjectName(QStringLiteral("nb_e"));
        nb_e->setGeometry(QRect(240, 280, 211, 22));
        pb_ajouter = new QPushButton(tab);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(60, 430, 102, 28));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(-60, 470, 1331, 161));
        label_7->setStyleSheet(QStringLiteral("border-image: url(:/img/img/qzd.jpg);"));
        pb_modifier = new QPushButton(tab);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(190, 430, 102, 28));
        pb_supprimer = new QPushButton(tab);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(350, 430, 102, 28));
        location_e = new QLineEdit(tab);
        location_e->setObjectName(QStringLiteral("location_e"));
        location_e->setGeometry(QRect(230, 340, 221, 22));
        dated_e = new QLineEdit(tab);
        dated_e->setObjectName(QStringLiteral("dated_e"));
        dated_e->setGeometry(QRect(240, 150, 191, 22));
        datef_e = new QLineEdit(tab);
        datef_e->setObjectName(QStringLiteral("datef_e"));
        datef_e->setGeometry(QRect(230, 210, 201, 22));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 30, 121, 41));
        nom_a = new QLineEdit(tab);
        nom_a->setObjectName(QStringLiteral("nom_a"));
        nom_a->setGeometry(QRect(230, 50, 221, 22));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tab_events_2 = new QTableView(tab_4);
        tab_events_2->setObjectName(QStringLiteral("tab_events_2"));
        tab_events_2->setGeometry(QRect(670, 110, 401, 281));
        pushButton_5 = new QPushButton(tab_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(110, 420, 102, 28));
        pushButton_6 = new QPushButton(tab_4);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(300, 420, 102, 28));
        pushButton_7 = new QPushButton(tab_4);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(500, 420, 102, 28));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tableView_2 = new QTableView(tab_2);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(30, 40, 1021, 341));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 430, 102, 28));
        tabWidget->addTab(tab_2, QString());
        label1 = new QLabel(pageevenement);
        label1->setObjectName(QStringLiteral("label1"));
        label1->setGeometry(QRect(-10, 20, 1401, 751));
        label1->setStyleSheet(QStringLiteral("border-image: url(:/img/img/background.jpg);"));
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
        label->raise();
        label1->raise();
        tabWidget->raise();
        commandLinkButton_24->raise();

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
        label_7->setText(QString());
        pb_modifier->setText(QApplication::translate("pageevenement", "Modifier", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("pageevenement", "Supprimer", Q_NULLPTR));
        label_9->setText(QApplication::translate("pageevenement", "Nom article", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pageevenement", "Ajouter", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pageevenement", "Trier", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("pageevenement", "Modifier", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("pageevenement", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("pageevenement", "gestion event", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pageevenement", "generer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("pageevenement", "statistique", Q_NULLPTR));
        label1->setText(QString());
        commandLinkButton_24->setText(QApplication::translate("pageevenement", "retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pageevenement: public Ui_pageevenement {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEEVENEMENT_H

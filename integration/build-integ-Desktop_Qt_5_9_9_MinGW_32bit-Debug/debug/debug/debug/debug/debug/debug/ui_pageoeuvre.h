/********************************************************************************
** Form generated from reading UI file 'pageoeuvre.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEOEUVRE_H
#define UI_PAGEOEUVRE_H

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
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pageoeuvre
{
public:
    QPushButton *pushButton_5;
    QLabel *label_19;
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *nom_o;
    QLineEdit *date_o;
    QLineEdit *prix_o;
    QLineEdit *discription_o;
    QPushButton *pb_supprimer;
    QPushButton *pb_modifier;
    QPushButton *pb_ajouter;
    QTableView *tab_oeuvre;
    QLabel *label;
    QLineEdit *nom_a;
    QCommandLinkButton *commandLinkButton_24;

    void setupUi(QDialog *Pageoeuvre)
    {
        if (Pageoeuvre->objectName().isEmpty())
            Pageoeuvre->setObjectName(QStringLiteral("Pageoeuvre"));
        Pageoeuvre->resize(1032, 731);
        pushButton_5 = new QPushButton(Pageoeuvre);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(320, 20, 93, 28));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        label_19 = new QLabel(Pageoeuvre);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(0, 0, 1031, 731));
        label_19->setStyleSheet(QStringLiteral("border-image: url(:/img/img/R.jpg);"));
        stackedWidget = new QStackedWidget(Pageoeuvre);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 60, 851, 541));
        stackedWidget->setStyleSheet(QLatin1String("/* styles.qss */\n"
"\n"
"* {\n"
"    font-family: \"Playfair Display\", serif; /* Fallback to generic serif font if Playfair Display is not available */\n"
"    color: black;\n"
"}\n"
"/* Style for QStackedWidget */\n"
"QStackedWidget {\n"
"    background-color: rgba(255, 255, 255, 0.9); /* Slightly transparent white background */\n"
"}\n"
"\n"
"\n"
"/* Style for QGroupBox */\n"
"\n"
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
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px;\n"
"    color: white;\n"
"}\n"
"\n"
"QComboBox QAbstractItem"
                        "View {\n"
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
"/* Additional styling for better appearance */\n"
"QPushButton:hover {\n"
"    background-color: #d35400; /* Darker orange color on hover */\n"
"}\n"
"\n"
""
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
"    background-color: rgba(255, 255, 255, 0.8); /* Slightly transparent white background */\n"
"    color: black;\n"
"    padding: 5px;\n"
"}\n"
""
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
"    border-bottom: none; /* Remove bottom border to create a top border effect */\n"
"}\n"
"\n"
"/* Style for unselected tabs */\n"
"QTabBar::tab {\n"
"    background-color: #e67e"
                        "22; /* Default background color for tabs */\n"
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
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 25, 141, 41));
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(30, 70, 121, 31));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 120, 101, 31));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 170, 121, 21));
        nom_o = new QLineEdit(page_2);
        nom_o->setObjectName(QStringLiteral("nom_o"));
        nom_o->setGeometry(QRect(170, 40, 113, 22));
        date_o = new QLineEdit(page_2);
        date_o->setObjectName(QStringLiteral("date_o"));
        date_o->setGeometry(QRect(170, 70, 113, 22));
        prix_o = new QLineEdit(page_2);
        prix_o->setObjectName(QStringLiteral("prix_o"));
        prix_o->setGeometry(QRect(170, 120, 113, 22));
        discription_o = new QLineEdit(page_2);
        discription_o->setObjectName(QStringLiteral("discription_o"));
        discription_o->setGeometry(QRect(170, 170, 113, 22));
        pb_supprimer = new QPushButton(page_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(180, 310, 93, 28));
        pb_modifier = new QPushButton(page_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(290, 310, 93, 28));
        pb_ajouter = new QPushButton(page_2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(50, 310, 93, 28));
        tab_oeuvre = new QTableView(page_2);
        tab_oeuvre->setObjectName(QStringLiteral("tab_oeuvre"));
        tab_oeuvre->setGeometry(QRect(380, 20, 431, 271));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 220, 111, 31));
        nom_a = new QLineEdit(page_2);
        nom_a->setObjectName(QStringLiteral("nom_a"));
        nom_a->setGeometry(QRect(170, 220, 113, 22));
        stackedWidget->addWidget(page_2);
        commandLinkButton_24 = new QCommandLinkButton(Pageoeuvre);
        commandLinkButton_24->setObjectName(QStringLiteral("commandLinkButton_24"));
        commandLinkButton_24->setGeometry(QRect(850, 10, 91, 41));
        commandLinkButton_24->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));

        retranslateUi(Pageoeuvre);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Pageoeuvre);
    } // setupUi

    void retranslateUi(QDialog *Pageoeuvre)
    {
        Pageoeuvre->setWindowTitle(QApplication::translate("Pageoeuvre", "Dialog", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Pageoeuvre", "Modif/Supr", Q_NULLPTR));
        label_19->setText(QString());
        label_7->setText(QApplication::translate("Pageoeuvre", "nom d'oeuvre", Q_NULLPTR));
        label_9->setText(QApplication::translate("Pageoeuvre", "date", Q_NULLPTR));
        label_10->setText(QApplication::translate("Pageoeuvre", "prix", Q_NULLPTR));
        label_11->setText(QApplication::translate("Pageoeuvre", "discription", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("Pageoeuvre", "supprimer", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("Pageoeuvre", "modifier", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("Pageoeuvre", "Ajouter", Q_NULLPTR));
        label->setText(QApplication::translate("Pageoeuvre", "nom artiste", Q_NULLPTR));
        commandLinkButton_24->setText(QApplication::translate("Pageoeuvre", "retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pageoeuvre: public Ui_Pageoeuvre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEOEUVRE_H

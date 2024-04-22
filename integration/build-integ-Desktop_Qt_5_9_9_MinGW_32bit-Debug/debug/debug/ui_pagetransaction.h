/********************************************************************************
** Form generated from reading UI file 'pagetransaction.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGETRANSACTION_H
#define UI_PAGETRANSACTION_H

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

class Ui_pagetransaction
{
public:
    QStackedWidget *stackedWidget;
    QWidget *page_2;
    QLineEdit *montant_t;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *id_t;
    QLineEdit *date_t;
    QLineEdit *statutpaiment_t;
    QLineEdit *type_t;
    QTableView *tab_trans;
    QPushButton *pb_supprimer;
    QPushButton *pb_modifier;
    QPushButton *pb_ajouter;
    QWidget *page_3;
    QTableView *tableView_2;
    QLabel *label_11;
    QLabel *label_12;
    QCommandLinkButton *commandLinkButton_24;

    void setupUi(QDialog *pagetransaction)
    {
        if (pagetransaction->objectName().isEmpty())
            pagetransaction->setObjectName(QStringLiteral("pagetransaction"));
        pagetransaction->resize(1349, 640);
        stackedWidget = new QStackedWidget(pagetransaction);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 40, 1251, 501));
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
        montant_t = new QLineEdit(page_2);
        montant_t->setObjectName(QStringLiteral("montant_t"));
        montant_t->setGeometry(QRect(860, 170, 251, 31));
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(860, 60, 211, 20));
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(860, 240, 201, 20));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(860, 150, 201, 20));
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(860, 380, 191, 20));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(860, 310, 211, 20));
        id_t = new QLineEdit(page_2);
        id_t->setObjectName(QStringLiteral("id_t"));
        id_t->setGeometry(QRect(860, 80, 251, 31));
        date_t = new QLineEdit(page_2);
        date_t->setObjectName(QStringLiteral("date_t"));
        date_t->setGeometry(QRect(860, 260, 251, 31));
        statutpaiment_t = new QLineEdit(page_2);
        statutpaiment_t->setObjectName(QStringLiteral("statutpaiment_t"));
        statutpaiment_t->setGeometry(QRect(860, 330, 251, 31));
        type_t = new QLineEdit(page_2);
        type_t->setObjectName(QStringLiteral("type_t"));
        type_t->setGeometry(QRect(860, 400, 251, 31));
        tab_trans = new QTableView(page_2);
        tab_trans->setObjectName(QStringLiteral("tab_trans"));
        tab_trans->setGeometry(QRect(15, 81, 791, 361));
        pb_supprimer = new QPushButton(page_2);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(1120, 450, 93, 28));
        pb_modifier = new QPushButton(page_2);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(980, 450, 93, 28));
        pb_ajouter = new QPushButton(page_2);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(830, 450, 93, 28));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        tableView_2 = new QTableView(page_3);
        tableView_2->setObjectName(QStringLiteral("tableView_2"));
        tableView_2->setGeometry(QRect(110, 130, 941, 361));
        label_11 = new QLabel(page_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(400, 60, 361, 41));
        stackedWidget->addWidget(page_3);
        label_12 = new QLabel(pagetransaction);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 0, 1351, 641));
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/img/img/R.jpg);"));
        commandLinkButton_24 = new QCommandLinkButton(pagetransaction);
        commandLinkButton_24->setObjectName(QStringLiteral("commandLinkButton_24"));
        commandLinkButton_24->setGeometry(QRect(1080, 0, 91, 41));
        commandLinkButton_24->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        label_12->raise();
        stackedWidget->raise();
        commandLinkButton_24->raise();

        retranslateUi(pagetransaction);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pagetransaction);
    } // setupUi

    void retranslateUi(QDialog *pagetransaction)
    {
        pagetransaction->setWindowTitle(QApplication::translate("pagetransaction", "Dialog", Q_NULLPTR));
        label_6->setText(QApplication::translate("pagetransaction", "id_transactions", Q_NULLPTR));
        label_7->setText(QApplication::translate("pagetransaction", "date_transactions", Q_NULLPTR));
        label_8->setText(QApplication::translate("pagetransaction", "montant", Q_NULLPTR));
        label_9->setText(QApplication::translate("pagetransaction", "type_transactions", Q_NULLPTR));
        label_10->setText(QApplication::translate("pagetransaction", "statut_paiment", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("pagetransaction", "Supprimer", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("pagetransaction", "modifier", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("pagetransaction", "Ajouter", Q_NULLPTR));
        label_11->setText(QApplication::translate("pagetransaction", "supprimer une transaction :", Q_NULLPTR));
        label_12->setText(QString());
        commandLinkButton_24->setText(QApplication::translate("pagetransaction", "retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pagetransaction: public Ui_pagetransaction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGETRANSACTION_H

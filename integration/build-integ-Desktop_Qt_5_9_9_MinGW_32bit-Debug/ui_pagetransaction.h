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
    QWidget *page_4;
    QLineEdit *searchTextBox;
    QTableView *tableView_3;
    QWidget *page;
    QLabel *label;
    QLabel *date_transactions;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_3;
    QLineEdit *montant;
    QLineEdit *date_transactions_2;
    QLineEdit *statut_paiement;
    QLineEdit *type_transaction;
    QPushButton *quitter;
    QPushButton *valider;
    QWidget *page_2;
    QLineEdit *montant_2;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *id_transactions;
    QLineEdit *date_transactions_3;
    QLineEdit *statut_paiment;
    QLineEdit *type_transactions;
    QTableView *tableView;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *page_3;
    QTableView *tableView_2;
    QLabel *label_11;
    QPushButton *pushButton;
    QLabel *label_12;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QCommandLinkButton *commandLinkButton_24;

    void setupUi(QDialog *pagetransaction)
    {
        if (pagetransaction->objectName().isEmpty())
            pagetransaction->setObjectName(QStringLiteral("pagetransaction"));
        pagetransaction->resize(1349, 640);
        stackedWidget = new QStackedWidget(pagetransaction);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(80, 40, 1251, 501));
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
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        searchTextBox = new QLineEdit(page_4);
        searchTextBox->setObjectName(QStringLiteral("searchTextBox"));
        searchTextBox->setGeometry(QRect(130, 51, 811, 51));
        tableView_3 = new QTableView(page_4);
        tableView_3->setObjectName(QStringLiteral("tableView_3"));
        tableView_3->setGeometry(QRect(140, 130, 811, 341));
        stackedWidget->addWidget(page_4);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 30, 271, 41));
        date_transactions = new QLabel(page);
        date_transactions->setObjectName(QStringLiteral("date_transactions"));
        date_transactions->setGeometry(QRect(360, 130, 191, 31));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(400, 90, 71, 31));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(370, 200, 151, 31));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(360, 280, 241, 41));
        montant = new QLineEdit(page);
        montant->setObjectName(QStringLiteral("montant"));
        montant->setGeometry(QRect(580, 90, 141, 22));
        date_transactions_2 = new QLineEdit(page);
        date_transactions_2->setObjectName(QStringLiteral("date_transactions_2"));
        date_transactions_2->setGeometry(QRect(580, 140, 141, 22));
        statut_paiement = new QLineEdit(page);
        statut_paiement->setObjectName(QStringLiteral("statut_paiement"));
        statut_paiement->setGeometry(QRect(580, 210, 141, 22));
        type_transaction = new QLineEdit(page);
        type_transaction->setObjectName(QStringLiteral("type_transaction"));
        type_transaction->setGeometry(QRect(580, 290, 151, 22));
        quitter = new QPushButton(page);
        quitter->setObjectName(QStringLiteral("quitter"));
        quitter->setGeometry(QRect(630, 390, 93, 28));
        valider = new QPushButton(page);
        valider->setObjectName(QStringLiteral("valider"));
        valider->setGeometry(QRect(470, 390, 93, 28));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        montant_2 = new QLineEdit(page_2);
        montant_2->setObjectName(QStringLiteral("montant_2"));
        montant_2->setGeometry(QRect(860, 170, 251, 31));
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(880, 10, 301, 41));
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
        id_transactions = new QLineEdit(page_2);
        id_transactions->setObjectName(QStringLiteral("id_transactions"));
        id_transactions->setGeometry(QRect(860, 80, 251, 31));
        date_transactions_3 = new QLineEdit(page_2);
        date_transactions_3->setObjectName(QStringLiteral("date_transactions_3"));
        date_transactions_3->setGeometry(QRect(860, 260, 251, 31));
        statut_paiment = new QLineEdit(page_2);
        statut_paiment->setObjectName(QStringLiteral("statut_paiment"));
        statut_paiment->setGeometry(QRect(860, 330, 251, 31));
        type_transactions = new QLineEdit(page_2);
        type_transactions->setObjectName(QStringLiteral("type_transactions"));
        type_transactions->setGeometry(QRect(860, 400, 251, 31));
        tableView = new QTableView(page_2);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(15, 81, 791, 361));
        pushButton_5 = new QPushButton(page_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1030, 450, 93, 28));
        pushButton_6 = new QPushButton(page_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(880, 450, 93, 28));
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
        pushButton = new QPushButton(pagetransaction);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(400, 10, 93, 28));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        label_12 = new QLabel(pagetransaction);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 0, 1351, 641));
        label_12->setStyleSheet(QStringLiteral("border-image: url(:/img/img/R.jpg);"));
        pushButton_3 = new QPushButton(pagetransaction);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(590, 10, 93, 28));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        pushButton_2 = new QPushButton(pagetransaction);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 10, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        pushButton_4 = new QPushButton(pagetransaction);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(820, 10, 93, 28));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
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
        pushButton->raise();
        pushButton_3->raise();
        pushButton_2->raise();
        pushButton_4->raise();
        commandLinkButton_24->raise();

        retranslateUi(pagetransaction);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(pagetransaction);
    } // setupUi

    void retranslateUi(QDialog *pagetransaction)
    {
        pagetransaction->setWindowTitle(QApplication::translate("pagetransaction", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("pagetransaction", "ajouter une transaction", Q_NULLPTR));
        date_transactions->setText(QApplication::translate("pagetransaction", "date_transactions", Q_NULLPTR));
        label_4->setText(QApplication::translate("pagetransaction", "montant", Q_NULLPTR));
        label_5->setText(QApplication::translate("pagetransaction", "statut_paiement", Q_NULLPTR));
        label_3->setText(QApplication::translate("pagetransaction", "type_transaction", Q_NULLPTR));
        quitter->setText(QApplication::translate("pagetransaction", "quitter", Q_NULLPTR));
        valider->setText(QApplication::translate("pagetransaction", "valider", Q_NULLPTR));
        label_2->setText(QApplication::translate("pagetransaction", "MODIFIER UNE TRANSACTION", Q_NULLPTR));
        label_6->setText(QApplication::translate("pagetransaction", "id_transactions", Q_NULLPTR));
        label_7->setText(QApplication::translate("pagetransaction", "date_transactions", Q_NULLPTR));
        label_8->setText(QApplication::translate("pagetransaction", "montant", Q_NULLPTR));
        label_9->setText(QApplication::translate("pagetransaction", "type_transactions", Q_NULLPTR));
        label_10->setText(QApplication::translate("pagetransaction", "statut_paiment", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pagetransaction", "quitter", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("pagetransaction", "valider", Q_NULLPTR));
        label_11->setText(QApplication::translate("pagetransaction", "supprimer une transaction :", Q_NULLPTR));
        pushButton->setText(QApplication::translate("pagetransaction", "modifier", Q_NULLPTR));
        label_12->setText(QString());
        pushButton_3->setText(QApplication::translate("pagetransaction", "chercher", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("pagetransaction", "ajouter", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("pagetransaction", "supprimer", Q_NULLPTR));
        commandLinkButton_24->setText(QApplication::translate("pagetransaction", "retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pagetransaction: public Ui_pagetransaction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGETRANSACTION_H

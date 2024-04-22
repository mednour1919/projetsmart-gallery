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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pageoeuvre
{
public:
    QPushButton *pushButton_5;
    QLabel *label_19;
    QPushButton *pushButton_4;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *lineEdit_ndo;
    QLineEdit *lineEdit_sa;
    QLineEdit *lineEdit_d;
    QLineEdit *lineEdit_p;
    QLineEdit *lineEdit_desc;
    QLineEdit *lineEdit_na;
    QPushButton *pushButton_ch;
    QWidget *page_2;
    QFrame *frame;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *lineEdit_;
    QLineEdit *lineEdit_sa1;
    QLineEdit *lineEdit_d1;
    QLineEdit *lineEdit_p1;
    QLineEdit *lineEdit_desc1;
    QLineEdit *lineEdit_na1;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *page_3;
    QFrame *frame_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *lineEdit_ndo2;
    QLineEdit *lineEdit_sa2;
    QLineEdit *lineEdit_d2;
    QLineEdit *lineEdit_p2;
    QLineEdit *lineEdit_desc2;
    QLineEdit *lineEdit_na2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
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
        pushButton_4 = new QPushButton(Pageoeuvre);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(460, 20, 93, 28));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
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
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        label = new QLabel(page);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 70, 111, 41));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 220, 101, 21));
        label_3 = new QLabel(page);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 360, 121, 31));
        label_4 = new QLabel(page);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(300, 70, 61, 31));
        label_5 = new QLabel(page);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 220, 101, 31));
        label_6 = new QLabel(page);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(280, 360, 111, 31));
        lineEdit_ndo = new QLineEdit(page);
        lineEdit_ndo->setObjectName(QStringLiteral("lineEdit_ndo"));
        lineEdit_ndo->setGeometry(QRect(140, 70, 113, 22));
        lineEdit_sa = new QLineEdit(page);
        lineEdit_sa->setObjectName(QStringLiteral("lineEdit_sa"));
        lineEdit_sa->setGeometry(QRect(130, 220, 113, 22));
        lineEdit_d = new QLineEdit(page);
        lineEdit_d->setObjectName(QStringLiteral("lineEdit_d"));
        lineEdit_d->setGeometry(QRect(130, 360, 113, 22));
        lineEdit_p = new QLineEdit(page);
        lineEdit_p->setObjectName(QStringLiteral("lineEdit_p"));
        lineEdit_p->setGeometry(QRect(360, 70, 113, 22));
        lineEdit_desc = new QLineEdit(page);
        lineEdit_desc->setObjectName(QStringLiteral("lineEdit_desc"));
        lineEdit_desc->setGeometry(QRect(390, 220, 113, 22));
        lineEdit_na = new QLineEdit(page);
        lineEdit_na->setObjectName(QStringLiteral("lineEdit_na"));
        lineEdit_na->setGeometry(QRect(390, 370, 113, 22));
        pushButton_ch = new QPushButton(page);
        pushButton_ch->setObjectName(QStringLiteral("pushButton_ch"));
        pushButton_ch->setGeometry(QRect(220, 420, 93, 28));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        frame = new QFrame(page_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(99, 59, 351, 231));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 285, 141, 41));
        label_8 = new QLabel(page_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 325, 121, 31));
        label_9 = new QLabel(page_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 360, 121, 31));
        label_10 = new QLabel(page_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 400, 141, 21));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 430, 121, 21));
        label_12 = new QLabel(page_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 460, 121, 21));
        lineEdit_ = new QLineEdit(page_2);
        lineEdit_->setObjectName(QStringLiteral("lineEdit_"));
        lineEdit_->setGeometry(QRect(150, 300, 113, 22));
        lineEdit_sa1 = new QLineEdit(page_2);
        lineEdit_sa1->setObjectName(QStringLiteral("lineEdit_sa1"));
        lineEdit_sa1->setGeometry(QRect(150, 330, 113, 22));
        lineEdit_d1 = new QLineEdit(page_2);
        lineEdit_d1->setObjectName(QStringLiteral("lineEdit_d1"));
        lineEdit_d1->setGeometry(QRect(150, 360, 113, 22));
        lineEdit_p1 = new QLineEdit(page_2);
        lineEdit_p1->setObjectName(QStringLiteral("lineEdit_p1"));
        lineEdit_p1->setGeometry(QRect(150, 400, 113, 22));
        lineEdit_desc1 = new QLineEdit(page_2);
        lineEdit_desc1->setObjectName(QStringLiteral("lineEdit_desc1"));
        lineEdit_desc1->setGeometry(QRect(150, 430, 113, 22));
        lineEdit_na1 = new QLineEdit(page_2);
        lineEdit_na1->setObjectName(QStringLiteral("lineEdit_na1"));
        lineEdit_na1->setGeometry(QRect(150, 460, 113, 22));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(120, 10, 93, 28));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 10, 93, 28));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        frame_2 = new QFrame(page_3);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(50, 80, 211, 161));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(page_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(250, 40, 151, 31));
        label_14 = new QLabel(page_3);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(230, 110, 171, 31));
        label_15 = new QLabel(page_3);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(260, 180, 121, 31));
        label_16 = new QLabel(page_3);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(260, 240, 101, 21));
        label_17 = new QLabel(page_3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(250, 290, 141, 31));
        label_18 = new QLabel(page_3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(250, 350, 151, 21));
        lineEdit_ndo2 = new QLineEdit(page_3);
        lineEdit_ndo2->setObjectName(QStringLiteral("lineEdit_ndo2"));
        lineEdit_ndo2->setGeometry(QRect(380, 50, 113, 22));
        lineEdit_sa2 = new QLineEdit(page_3);
        lineEdit_sa2->setObjectName(QStringLiteral("lineEdit_sa2"));
        lineEdit_sa2->setGeometry(QRect(380, 110, 113, 22));
        lineEdit_d2 = new QLineEdit(page_3);
        lineEdit_d2->setObjectName(QStringLiteral("lineEdit_d2"));
        lineEdit_d2->setGeometry(QRect(380, 180, 113, 22));
        lineEdit_p2 = new QLineEdit(page_3);
        lineEdit_p2->setObjectName(QStringLiteral("lineEdit_p2"));
        lineEdit_p2->setGeometry(QRect(380, 240, 113, 22));
        lineEdit_desc2 = new QLineEdit(page_3);
        lineEdit_desc2->setObjectName(QStringLiteral("lineEdit_desc2"));
        lineEdit_desc2->setGeometry(QRect(380, 290, 113, 22));
        lineEdit_na2 = new QLineEdit(page_3);
        lineEdit_na2->setObjectName(QStringLiteral("lineEdit_na2"));
        lineEdit_na2->setGeometry(QRect(380, 350, 113, 22));
        pushButton_3 = new QPushButton(page_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 400, 93, 28));
        stackedWidget->addWidget(page_3);
        pushButton_6 = new QPushButton(Pageoeuvre);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(170, 20, 93, 28));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
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

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Pageoeuvre);
    } // setupUi

    void retranslateUi(QDialog *Pageoeuvre)
    {
        Pageoeuvre->setWindowTitle(QApplication::translate("Pageoeuvre", "Dialog", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Pageoeuvre", "Modif/Supr", Q_NULLPTR));
        label_19->setText(QString());
        pushButton_4->setText(QApplication::translate("Pageoeuvre", "Chercher", Q_NULLPTR));
        label->setText(QApplication::translate("Pageoeuvre", "nom d'oeuvre", Q_NULLPTR));
        label_2->setText(QApplication::translate("Pageoeuvre", "style artistique", Q_NULLPTR));
        label_3->setText(QApplication::translate("Pageoeuvre", "date", Q_NULLPTR));
        label_4->setText(QApplication::translate("Pageoeuvre", "prix", Q_NULLPTR));
        label_5->setText(QApplication::translate("Pageoeuvre", "description", Q_NULLPTR));
        label_6->setText(QApplication::translate("Pageoeuvre", "nom artiste", Q_NULLPTR));
        pushButton_ch->setText(QApplication::translate("Pageoeuvre", "chercher", Q_NULLPTR));
        label_7->setText(QApplication::translate("Pageoeuvre", "nom d'oeuvre", Q_NULLPTR));
        label_8->setText(QApplication::translate("Pageoeuvre", "style artistique", Q_NULLPTR));
        label_9->setText(QApplication::translate("Pageoeuvre", "date", Q_NULLPTR));
        label_10->setText(QApplication::translate("Pageoeuvre", "prix", Q_NULLPTR));
        label_11->setText(QApplication::translate("Pageoeuvre", "description", Q_NULLPTR));
        label_12->setText(QApplication::translate("Pageoeuvre", "nom artiste", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Pageoeuvre", "supprimer", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Pageoeuvre", "modifier", Q_NULLPTR));
        label_13->setText(QApplication::translate("Pageoeuvre", "nom d'oeuvre", Q_NULLPTR));
        label_14->setText(QApplication::translate("Pageoeuvre", "style artistique", Q_NULLPTR));
        label_15->setText(QApplication::translate("Pageoeuvre", "date", Q_NULLPTR));
        label_16->setText(QApplication::translate("Pageoeuvre", "prix", Q_NULLPTR));
        label_17->setText(QApplication::translate("Pageoeuvre", "description", Q_NULLPTR));
        label_18->setText(QApplication::translate("Pageoeuvre", "nom artiste", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Pageoeuvre", "confirmer", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Pageoeuvre", "Ajouter", Q_NULLPTR));
        commandLinkButton_24->setText(QApplication::translate("Pageoeuvre", "retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Pageoeuvre: public Ui_Pageoeuvre {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEOEUVRE_H

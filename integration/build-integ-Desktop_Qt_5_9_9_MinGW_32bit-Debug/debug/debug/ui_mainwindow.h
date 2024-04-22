/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1195, 824);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 1141, 761));
        label->setStyleSheet(QStringLiteral("border-image: url(:/img/img/R.jpg);"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(110, 90, 93, 28));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"    font-family: 'Lovelo', sans-serif; /* Add the 'Lovelo' font and fallback to a generic sans-serif font */\n"
"}\n"
""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 180, 93, 28));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"    font-family: \"lovelo\", sans-serif; /* Use \"lovelo\" font, fallback to sans-serif if not available */\n"
"}\n"
""));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 260, 93, 28));
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(620, 310, 93, 28));
        pushButton_4->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(790, 390, 93, 28));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(900, 480, 93, 28));
        pushButton_6->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(490, 50, 361, 131));
        label_2->setStyleSheet(QStringLiteral(""));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1195, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Personnel", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Artiste", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Oeuvre", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Evenement", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Client", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Transaction", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:28pt; font-weight:600;\">ARTVUE</span></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

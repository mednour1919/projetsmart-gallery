/********************************************************************************
** Form generated from reading UI file 'pageartiste.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEARTISTE_H
#define UI_PAGEARTISTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pageartiste
{
public:
    QStackedWidget *gridStackedWidget;
    QWidget *gridStackedWidgetPage1;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_13;
    QTableView *tab_artist;
    QPushButton *pb_modifier;
    QPushButton *pb_supprimer;
    QLineEdit *nom_a;
    QLineEdit *status_a;
    QLineEdit *oeuvresmaj_a;
    QLineEdit *email_a;
    QLineEdit *styleart_a;
    QPushButton *pb_ajouter;
    QLabel *label_33;
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QLabel *label_11;
    QLineEdit *le_idsupp;
    QPushButton *pb_supprimerq;
    QLabel *label_48;
    QLabel *label_35;
    QWidget *tab_5;
    QGroupBox *groupBox_4;
    QLabel *label_12;
    QLineEdit *le_idrech;
    QTableView *tab_normes_rech;
    QPushButton *pushButton_5;
    QLabel *label_47;
    QLabel *label_36;
    QLabel *label_14;
    QCommandLinkButton *commandLinkButton_25;
    QCommandLinkButton *commandLinkButton_24;

    void setupUi(QDialog *pageartiste)
    {
        if (pageartiste->objectName().isEmpty())
            pageartiste->setObjectName(QStringLiteral("pageartiste"));
        pageartiste->resize(1185, 752);
        gridStackedWidget = new QStackedWidget(pageartiste);
        gridStackedWidget->setObjectName(QStringLiteral("gridStackedWidget"));
        gridStackedWidget->setGeometry(QRect(170, 40, 921, 681));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(gridStackedWidget->sizePolicy().hasHeightForWidth());
        gridStackedWidget->setSizePolicy(sizePolicy);
        gridStackedWidget->setStyleSheet(QLatin1String("/* styles.qss */\n"
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
        gridStackedWidgetPage1 = new QWidget();
        gridStackedWidgetPage1->setObjectName(QStringLiteral("gridStackedWidgetPage1"));
        gridLayout = new QGridLayout(gridStackedWidgetPage1);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 30, -1, -1);
        tabWidget = new QTabWidget(gridStackedWidgetPage1);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setStyleSheet(QLatin1String("QWidget#tab{\n"
"\n"
"background-image: url(:/images/file cover - 1.png);\n"
"background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"}\n"
"QWidget#tab_3{\n"
"\n"
"background-image: url(:/images/file cover - 1.png);\n"
"background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"}\n"
"QWidget#tab_4{\n"
"\n"
"background-image: url(:/images/file cover - 1.png);\n"
"background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"}\n"
"QWidget#tab_2{\n"
"\n"
"background-image: url(:/images/file cover - 1.png);\n"
"background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"}\n"
"QWidget#tab_5{\n"
"\n"
"background-image: url(:/images/file cover - 1.png);\n"
"background-repeat: no-repeat;\n"
"    background-position: center;\n"
"    background-size: cover;\n"
"}"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 0, 881, 581));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 60, 81, 31));
        label->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 150, 121, 21));
        label_3->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 210, 121, 31));
        label_4->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 270, 151, 31));
        label_5->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(20, 360, 141, 31));
        label_13->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        tab_artist = new QTableView(groupBox);
        tab_artist->setObjectName(QStringLiteral("tab_artist"));
        tab_artist->setGeometry(QRect(420, 50, 431, 421));
        pb_modifier = new QPushButton(groupBox);
        pb_modifier->setObjectName(QStringLiteral("pb_modifier"));
        pb_modifier->setGeometry(QRect(270, 520, 93, 28));
        pb_supprimer = new QPushButton(groupBox);
        pb_supprimer->setObjectName(QStringLiteral("pb_supprimer"));
        pb_supprimer->setGeometry(QRect(420, 520, 93, 28));
        nom_a = new QLineEdit(groupBox);
        nom_a->setObjectName(QStringLiteral("nom_a"));
        nom_a->setGeometry(QRect(160, 60, 113, 22));
        status_a = new QLineEdit(groupBox);
        status_a->setObjectName(QStringLiteral("status_a"));
        status_a->setGeometry(QRect(180, 140, 113, 22));
        oeuvresmaj_a = new QLineEdit(groupBox);
        oeuvresmaj_a->setObjectName(QStringLiteral("oeuvresmaj_a"));
        oeuvresmaj_a->setGeometry(QRect(190, 220, 113, 22));
        email_a = new QLineEdit(groupBox);
        email_a->setObjectName(QStringLiteral("email_a"));
        email_a->setGeometry(QRect(180, 270, 113, 22));
        styleart_a = new QLineEdit(groupBox);
        styleart_a->setObjectName(QStringLiteral("styleart_a"));
        styleart_a->setGeometry(QRect(160, 370, 113, 22));
        pb_ajouter = new QPushButton(groupBox);
        pb_ajouter->setObjectName(QStringLiteral("pb_ajouter"));
        pb_ajouter->setGeometry(QRect(90, 520, 93, 28));
        label_33 = new QLabel(tab);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setGeometry(QRect(-10, -20, 1101, 541));
        label_33->setPixmap(QPixmap(QString::fromUtf8("../../palette.jpg")));
        label_33->setScaledContents(true);
        tabWidget->addTab(tab, QString());
        label_33->raise();
        groupBox->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(50, 20, 781, 491));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 130, 81, 31));
        label_11->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        le_idsupp = new QLineEdit(groupBox_3);
        le_idsupp->setObjectName(QStringLiteral("le_idsupp"));
        le_idsupp->setGeometry(QRect(120, 130, 131, 31));
        le_idsupp->setStyleSheet(QLatin1String("box-sizing: border-box;\n"
"\n"
"position: absolute;\n"
"width: 428px;\n"
"height: 50px;\n"
"left: 1122px;\n"
"top: 327px;\n"
"\n"
"border: 2px solid #D9D9D9;\n"
"border-radius: 8px;"));
        pb_supprimerq = new QPushButton(groupBox_3);
        pb_supprimerq->setObjectName(QStringLiteral("pb_supprimerq"));
        pb_supprimerq->setGeometry(QRect(260, 130, 121, 28));
        pb_supprimerq->setMinimumSize(QSize(93, 28));
        pb_supprimerq->setStyleSheet(QLatin1String("QPushButton{\n"
"	padding: 0px 16px;\n"
"\n"
"\n"
"width: 86px;\n"
"height: 48px;\n"
"left: 1996px;\n"
"top: 64px;\n"
"\n"
"/* Blue/50 */\n"
"background: #0E33F2;\n"
"border-radius: 12px;\n"
"\n"
"\n"
"/* Button */\n"
"\n"
"width: 54px;\n"
"height: 24px;\n"
"\n"
"font-family: 'Inter';\n"
"font-style: normal;\n"
"font-weight: 800;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"/* identical to box height, or 150% */\n"
"\n"
"/* Base/100 */\n"
"color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	padding: 0px 16px;\n"
"\n"
"\n"
"width: 86px;\n"
"height: 48px;\n"
"left: 1996px;\n"
"top: 64px;\n"
"\n"
"/* Blue/50 */\n"
"background: #0B28C2;\n"
"border-radius: 12px;\n"
"\n"
"\n"
"/* Button */\n"
"\n"
"width: 54px;\n"
"height: 24px;\n"
"\n"
"font-family: 'Inter';\n"
"font-style: normal;\n"
"font-weight: 800;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"/* identical to box height, or 150% */\n"
"\n"
"/* Base/100 */\n"
"color: #FFFFFF;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"	padding: 0px 16px;\n"
"\n"
"\n"
""
                        "width: 86px;\n"
"height: 48px;\n"
"left: 1996px;\n"
"top: 64px;\n"
"\n"
"/* Blue/50 */\n"
"background: #081E91;\n"
"border-radius: 12px;\n"
"\n"
"\n"
"/* Button */\n"
"\n"
"width: 54px;\n"
"height: 24px;\n"
"\n"
"font-family: 'Inter';\n"
"font-style: normal;\n"
"font-weight: 800;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"/* identical to box height, or 150% */\n"
"\n"
"/* Base/100 */\n"
"color: #FFFFFF;\n"
"}"));
        label_48 = new QLabel(groupBox_3);
        label_48->setObjectName(QStringLiteral("label_48"));
        label_48->setGeometry(QRect(510, 10, 191, 151));
        label_48->setPixmap(QPixmap(QString::fromUtf8("../../Untitled.png")));
        label_48->setScaledContents(true);
        label_35 = new QLabel(tab_2);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setGeometry(QRect(-10, -10, 1101, 541));
        label_35->setPixmap(QPixmap(QString::fromUtf8("../../palette.jpg")));
        label_35->setScaledContents(true);
        tabWidget->addTab(tab_2, QString());
        label_35->raise();
        groupBox_3->raise();
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 30, 750, 441));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(70, 90, 81, 21));
        label_12->setStyleSheet(QStringLiteral("font: 87 9pt \"Arial Black\";"));
        le_idrech = new QLineEdit(groupBox_4);
        le_idrech->setObjectName(QStringLiteral("le_idrech"));
        le_idrech->setGeometry(QRect(130, 90, 113, 22));
        le_idrech->setStyleSheet(QLatin1String("box-sizing: border-box;\n"
"\n"
"position: absolute;\n"
"width: 428px;\n"
"height: 50px;\n"
"left: 1122px;\n"
"top: 327px;\n"
"\n"
"border: 2px solid #D9D9D9;\n"
"border-radius: 8px;"));
        tab_normes_rech = new QTableView(groupBox_4);
        tab_normes_rech->setObjectName(QStringLiteral("tab_normes_rech"));
        tab_normes_rech->setGeometry(QRect(20, 200, 711, 201));
        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(260, 90, 131, 28));
        pushButton_5->setMinimumSize(QSize(93, 28));
        pushButton_5->setStyleSheet(QLatin1String("QPushButton{\n"
"	padding: 0px 16px;\n"
"\n"
"\n"
"width: 86px;\n"
"height: 48px;\n"
"left: 1996px;\n"
"top: 64px;\n"
"\n"
"/* Blue/50 */\n"
"background: #0E33F2;\n"
"border-radius: 12px;\n"
"\n"
"\n"
"/* Button */\n"
"\n"
"width: 54px;\n"
"height: 24px;\n"
"\n"
"font-family: 'Inter';\n"
"font-style: normal;\n"
"font-weight: 800;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"/* identical to box height, or 150% */\n"
"\n"
"/* Base/100 */\n"
"color: #FFFFFF;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	padding: 0px 16px;\n"
"\n"
"\n"
"width: 86px;\n"
"height: 48px;\n"
"left: 1996px;\n"
"top: 64px;\n"
"\n"
"/* Blue/50 */\n"
"background: #0B28C2;\n"
"border-radius: 12px;\n"
"\n"
"\n"
"/* Button */\n"
"\n"
"width: 54px;\n"
"height: 24px;\n"
"\n"
"font-family: 'Inter';\n"
"font-style: normal;\n"
"font-weight: 800;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"/* identical to box height, or 150% */\n"
"\n"
"/* Base/100 */\n"
"color: #FFFFFF;\n"
"}\n"
"\n"
"\n"
"QPushButton:pressed{\n"
"	padding: 0px 16px;\n"
"\n"
"\n"
""
                        "width: 86px;\n"
"height: 48px;\n"
"left: 1996px;\n"
"top: 64px;\n"
"\n"
"/* Blue/50 */\n"
"background: #081E91;\n"
"border-radius: 12px;\n"
"\n"
"\n"
"/* Button */\n"
"\n"
"width: 54px;\n"
"height: 24px;\n"
"\n"
"font-family: 'Inter';\n"
"font-style: normal;\n"
"font-weight: 800;\n"
"font-size: 16px;\n"
"line-height: 24px;\n"
"/* identical to box height, or 150% */\n"
"\n"
"/* Base/100 */\n"
"color: #FFFFFF;\n"
"}"));
        label_47 = new QLabel(groupBox_4);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setGeometry(QRect(550, 0, 191, 151));
        label_47->setPixmap(QPixmap(QString::fromUtf8("../../Untitled.png")));
        label_47->setScaledContents(true);
        label_36 = new QLabel(tab_5);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setGeometry(QRect(-30, 0, 1101, 541));
        label_36->setPixmap(QPixmap(QString::fromUtf8("../../palette.jpg")));
        label_36->setScaledContents(true);
        tabWidget->addTab(tab_5, QString());
        label_36->raise();
        groupBox_4->raise();

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        gridStackedWidget->addWidget(gridStackedWidgetPage1);
        label_14 = new QLabel(pageartiste);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 0, 1201, 741));
        label_14->setStyleSheet(QStringLiteral("border-image: url(:/img/img/R.jpg);"));
        commandLinkButton_25 = new QCommandLinkButton(pageartiste);
        commandLinkButton_25->setObjectName(QStringLiteral("commandLinkButton_25"));
        commandLinkButton_25->setGeometry(QRect(1100, 310, 91, 41));
        commandLinkButton_24 = new QCommandLinkButton(pageartiste);
        commandLinkButton_24->setObjectName(QStringLiteral("commandLinkButton_24"));
        commandLinkButton_24->setGeometry(QRect(900, 0, 91, 41));
        commandLinkButton_24->setStyleSheet(QLatin1String("QPushButton {\n"
"    background-color: rgba(230, 126, 34, 0.9); /* Slightly transparent orange background */\n"
"    border: 1px solid #d35400; /* Change to a darker orange color */\n"
"    border-radius: 5px;\n"
"    padding: 5px 10px;\n"
"    color: white;\n"
"}"));
        label_14->raise();
        gridStackedWidget->raise();
        commandLinkButton_25->raise();
        commandLinkButton_24->raise();

        retranslateUi(pageartiste);

        gridStackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pageartiste);
    } // setupUi

    void retranslateUi(QDialog *pageartiste)
    {
        pageartiste->setWindowTitle(QApplication::translate("pageartiste", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("pageartiste", "Ajout", Q_NULLPTR));
        label->setText(QApplication::translate("pageartiste", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("pageartiste", "status", Q_NULLPTR));
        label_4->setText(QApplication::translate("pageartiste", "oeuvresmaj", Q_NULLPTR));
        label_5->setText(QApplication::translate("pageartiste", "email", Q_NULLPTR));
        label_13->setText(QApplication::translate("pageartiste", "styleart", Q_NULLPTR));
        pb_modifier->setText(QApplication::translate("pageartiste", "Modifier", Q_NULLPTR));
        pb_supprimer->setText(QApplication::translate("pageartiste", "Supprimer", Q_NULLPTR));
        pb_ajouter->setText(QApplication::translate("pageartiste", "Ajouter", Q_NULLPTR));
        label_33->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("pageartiste", "Ajouter", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("pageartiste", "Supprimer", Q_NULLPTR));
        label_11->setText(QApplication::translate("pageartiste", "ID", Q_NULLPTR));
        le_idsupp->setPlaceholderText(QApplication::translate("pageartiste", "ID", Q_NULLPTR));
        pb_supprimerq->setText(QApplication::translate("pageartiste", "Supprimer", Q_NULLPTR));
        label_48->setText(QString());
        label_35->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("pageartiste", "Supprimer", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("pageartiste", "Recherche", Q_NULLPTR));
        label_12->setText(QApplication::translate("pageartiste", "ID", Q_NULLPTR));
        le_idrech->setPlaceholderText(QApplication::translate("pageartiste", "ID", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("pageartiste", "Rechercher", Q_NULLPTR));
        label_47->setText(QString());
        label_36->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("pageartiste", "Rechercher", Q_NULLPTR));
        label_14->setText(QApplication::translate("pageartiste", "TextLabel", Q_NULLPTR));
        commandLinkButton_25->setText(QApplication::translate("pageartiste", "retour", Q_NULLPTR));
        commandLinkButton_24->setText(QApplication::translate("pageartiste", "retour", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class pageartiste: public Ui_pageartiste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEARTISTE_H

#include "artiste.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QIntValidator>
#include<QSqlError>
#include<QString>
#include<QComboBox>
#include <QCoreApplication>
#include <QFileDialog>
#include <QPrinter>
#include <QPainter>
#include <QStandardItemModel>


     Artiste::Artiste (int ida,QString  nom_a,QString  status_a ,QString oeuvresmaj_a,QString email_a,QString styleart_a)
      {
         this-> ida=ida;
        this->nom_a = nom_a ;
      this->status_a=status_a;
         this->oeuvresmaj_a=oeuvresmaj_a ;
         this->email_a = email_a;
         this->styleart_a= styleart_a ;
     }

     bool Artiste::ajouter()
     {
         QSqlQuery query;
         query.prepare("insert into artiste (nom_a,status_a,oeuvresmaj_a,email_a,styleart_a)""values( :nom_a, :status_a, :oeuvresmaj_a, :email_a, :styleart_a)");
         QString res = QString::number(ida) ;
         query.bindValue(":ida",res);
         query.bindValue(":nom_a", nom_a);
         query.bindValue(":status_a", status_a);
         query.bindValue(":oeuvresmaj_a", oeuvresmaj_a);
         query.bindValue(":email_a", email_a);
         query.bindValue(":styleart_a", styleart_a);

         return query.exec();
     }





    QSqlQueryModel* Artiste::afficher()
    {

        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * from artiste");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ida"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom_a"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" status_a "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr(" oeuvresmaj_a"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("email_a"));
            model->setHeaderData(5, Qt::Horizontal, QObject::tr("styleart_a"));



        return model;
    }
    bool Artiste::supprimer(int ida)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM artiste WHERE ida=:ida");
        query.bindValue(":ida",ida);
        return query.exec();
    }
    bool Artiste::checkIfArtisteExists(QString nom_a)
    {
        QSqlQuery query;
        query.prepare("SELECT nom_a FROM artiste where nom_a=:nom_a");
        query.bindValue(":nom_a", nom_a);
        if (query.exec() && query.next()) {
            return true;
        } else {
            return false;
        }
    }
    bool Artiste::modifierE(int ida) {
        QSqlQuery query;

        query.prepare("UPDATE artiste SET nom_a = :nom_a, status_a = :status_a, oeuvresmaj_a = :oeuvresmaj_a, email_a = :email_a, styleart_a = :styleart_a WHERE ida = :ida");
        query.bindValue(":nom_a", nom_a);
        query.bindValue(":status_a", status_a);
        query.bindValue(":oeuvresmaj_a", oeuvresmaj_a);
        query.bindValue(":email_a", email_a);
        query.bindValue(":styleart_a", styleart_a);
        query.bindValue(":ida", ida);

        return query.exec();
    }

    QSqlQueryModel* Artiste::afficher1()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM artiste ORDER BY nom_a ASC"); // ASC for ascending order
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ida"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" status "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr(" oeuvresmaj"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("styleart"));

        return model;
    }

    int Artiste::exporterPDF(QAbstractItemModel* model)
    {
        QPrinter printer;
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setOutputFileName("C:/Users/mahdi/Downloads/nourinteg/nourinteg/integration/integ/Save.pdf");
        QPainter painter;
        if (!printer.isValid()) {
            qWarning("Failed to create the printer object.");
            return 1;
        }
        if (!painter.begin(&printer)) {
            qWarning("Failed to open the printer, is it writable?");
            return 1;
        }

        // Add title
        QString title = "Voici le tableau d'artiste :";
        painter.drawText(10, 10, title);

        // Set up table formatting
        const int columnWidth = 200;
        const int rowHeight = 20;
        const int startX = 10;
        const int startY = 30;

        // Draw table headers
        QStringList headers = { "ID", "NOM", "STATUS", "OEUVRE", "EMAIL","STYLE" };
        for (int i = 0; i < headers.size(); ++i) {
            painter.drawText(startX + i * columnWidth, startY, headers[i]);
        }

        // Draw table content
        int rowCount = model->rowCount();
        int columnCount = model->columnCount();
        for (int row = 0; row < rowCount; ++row) {
            for (int column = 0; column < columnCount; ++column) {
                QModelIndex index = model->index(row, column);
                QVariant data = model->data(index);
                QString text = data.toString();
                painter.drawText(startX + column * columnWidth, startY + (row + 1) * rowHeight, text);
            }
        }

        painter.end();

        return 0;
    }
    QSqlQueryModel* Artiste::rechercher(const QString& recherche) {
        QSqlQueryModel* model = new QSqlQueryModel();
        QString queryStr = "SELECT * FROM artiste WHERE nom_a LIKE '%" + recherche + "%'";
        model->setQuery(queryStr);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("ida"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" status "));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr(" oeuvresmaj"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("styleart"));
        return model;
    }

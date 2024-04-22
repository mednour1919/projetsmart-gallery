#include "artiste.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QIntValidator>
#include<QSqlError>
#include<QString>
#include<QComboBox>
#include <QCoreApplication>
Artiste::Artiste()
{
    nom_a="";
     status_a="";
     oeuvresmaj_a ="";
     email_a="";
     styleart_a="";

    }
     Artiste::Artiste (QString  nom_a,QString  status_a ,QString oeuvresmaj_a,QString email_a,QString styleart_a)
      {
        this->nom_a = nom_a ;
      this->status_a=status_a;
         this->oeuvresmaj_a=oeuvresmaj_a ;
         this->email_a = email_a;
         this->styleart_a= styleart_a ;
     }
    QString Artiste::getnom_a(){return nom_a ;}
     QString Artiste::getstatus_a(){return status_a ;}
     QString Artiste::getoeuvresmaj_a(){return oeuvresmaj_a ;}
    QString Artiste::getemail_a(){return email_a ;}
     QString Artiste::getstyleart_a(){return styleart_a ;}



    void Artiste:: setnom_a(QString nom_a ){this->nom_a =nom_a ;}
    void Artiste:: setstatus_a(QString status_a ){this->status_a =status_a ;}
  void Artiste:: setoeuvresmaj_a(QString oeuvresmaj_a ){this->oeuvresmaj_a =oeuvresmaj_a ;}
   void Artiste:: setemail_a(QString email_a ){this->email_a =email_a ;}
void Artiste:: setstyleart_a(QString styleart_a ){this->styleart_a =styleart_a;}

  bool Artiste::ajouter()
  {
      QSqlQuery query;
      query.bindValue(":titre_e", QString(nom_a));

      query.prepare("INSERT INTO artiste (nom_a, status_a, oeuvresmaj_a, email_a, styleart_a) "
                    "VALUES (:nom_a, :status_a, :oeuvresmaj_a, :email_a, :styleart_a)");

      query.bindValue(":nom_a", nom_a);
         query.bindValue(":status_a", status_a);
         query.bindValue(":oeuvresmaj_a", oeuvresmaj_a);
         query.bindValue(":email_a", email_a);
         query.bindValue(":styleart_a", styleart_a);

;

         return query.exec();
     }


    QSqlQueryModel* Artiste::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * from artiste");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" status "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" oeuvresmaj"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("styleart"));



        return model;
    }
    bool Artiste::supprimer(QString nom_a)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM artiste WHERE nom_a = :nom_a");
        query.bindValue(":nom_a", nom_a);
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
    bool Artiste::modifierE(QString nom_a)
     {
        QSqlQuery query;
              query.prepare("UPDATE artiste SET status_a=:status_a , oeuvresmaj_a=:oeuvresmaj_a,email_a=:email_a,styleart_a=:styleart_a WHERE nom_a=:nom_a  " );
              query.bindValue(":nom_a", QString(nom_a));
                        query.bindValue(":status_a",status_a);
             query.bindValue(":oeuvresmaj_a",oeuvresmaj_a);
               query.bindValue(":email_a",email_a);
                  query.bindValue(":styleart_a",styleart_a);
              return  query.exec();



     }



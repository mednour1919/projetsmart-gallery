#include "oeuvre.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QIntValidator>
#include<QSqlError>
#include<QString>
#include<QComboBox>
#include <QCoreApplication>
Oeuvre::Oeuvre()
{
     nom_o="";
     date_o ="";
       prix_o = 0;
     discription_o="";
     nom_a="";


    }
     Oeuvre::Oeuvre (QString  nom_o,QString  date_o ,int prix_o,QString discription_o)
      {
        this->nom_o = nom_o ;
      this->date_o=date_o ;
         this->prix_o=prix_o;
         this->discription_o = discription_o;

     }
    QString Oeuvre::getnom_o(){return nom_o ;}
    QString Oeuvre::getdate_o(){return date_o;}
     int Oeuvre::getprix_o(){return prix_o ;}
     QString Oeuvre::getdiscription_o(){return discription_o ;}


    void Oeuvre:: setnom_o(QString nom_o ){this->nom_o =nom_o ;}
    void Oeuvre:: setdate_o(QString date_o ){this->date_o =date_o ;}
  void Oeuvre:: setprix_o(int prix_o ){this->prix_o =prix_o ;}
   void Oeuvre:: setdiscription_o(QString discription_o ){this->discription_o =discription_o ;}

   bool Oeuvre::ajouter()
   {
       QSqlQuery query;
       query.prepare("INSERT INTO deuvre (nom_o, date_o, prix_o, discription_o, nom_a) "
                     "VALUES (:nom_o, :date_o, :prix_o, :discription_o, :nom_a)");

       query.bindValue(":nom_o", nom_o);
       query.bindValue(":date_o", date_o);
       query.bindValue(":prix_o", prix_o);
       query.bindValue(":discription_o", discription_o);
       query.bindValue(":nom_a", nom_a);


       return query.exec();
   }




   QSqlQueryModel* Oeuvre::afficher()
   {
       QSqlQueryModel* model = new QSqlQueryModel();
       model->setQuery("select * from deuvre");




       return model;
   }

    bool Oeuvre::supprimer(QString nom_o)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM deuvre  WHERE nom_o = :nom_o");
        query.bindValue(":nom_o", nom_o);
        return query.exec();
    }
    bool Oeuvre::checkIfOeuvreExists(QString nom_o)
    {
        QSqlQuery query;
        query.prepare("SELECT nom_o FROM deuvre  where nom_o=:nom_o");
        query.bindValue(":nom_o", nom_o);
        if (query.exec() && query.next()) {
            return true;
        } else {
            return false;
        }
    }
    bool Oeuvre::modifierE(QString nom_o)
    {
        QSqlQuery query;
        query.prepare("UPDATE deuvre SET date_o=:date_o, prix_o=:prix_o, discription_o=:discription_o, nom_a=:nom_a WHERE nom_o=:nom_o");

        query.bindValue(":nom_o", nom_o);
        query.bindValue(":date_o", date_o);
        query.bindValue(":prix_o", prix_o);
        query.bindValue(":discription_o", discription_o);
        query.bindValue(":nom_a", nom_a);


        return query.exec();
    }


    QString Oeuvre::getnom_a() { return nom_a; }
    void Oeuvre::setnom_a(QString nom_a) { this->nom_a = nom_a; }

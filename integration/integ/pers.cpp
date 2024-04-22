#include "pers.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QIntValidator>
#include<QSqlError>
#include<QString>
#include<QComboBox>
#include <QCoreApplication>
Pers::Pers()
{
     id_p= 0;
     email_p="";
     password_p="";
     nom_p="";
     dateemb_p="";
     salaire_p= 0;

    }
     Pers::Pers (int  id_p,QString email_p,QString password_p,QString nom_p,QString dateemb_p,int  salaire_p)
      {
        this->id_p = id_p  ;
      this->email_p=email_p ;
         this->password_p=password_p ;
         this->nom_p = nom_p;
         this->dateemb_p= dateemb_p;
         this->salaire_p= salaire_p;

     }
   int Pers::getid_p(){return id_p ;}
QString Pers::getpassword_p(){return password_p ;}
   QString Pers::getemail_p(){return email_p ;}
    QString Pers::getnom_p(){return nom_p;}
    QString Pers::getdateemb_p(){return dateemb_p ;}
     int Pers::getsalaire_p(){return salaire_p ;}




    void Pers:: setid_p(int id_p ){this->id_p =id_p;}
   void Pers:: setpassword_p(QString password_p ){this->password_p =password_p;}
   void Pers:: setemail_p(QString email_p ){this->email_p=email_p;}
   void Pers:: setnom_p(QString nom_p ){this->nom_p=nom_p;}
   void Pers:: setdateemb_p(QString dateemb_p ){this->dateemb_p=dateemb_p;}
   void Pers:: setsalaire_p(int salaire_p ){this->salaire_p =salaire_p;}


   bool Pers::ajouter()
   {
       QSqlQuery query;
       query.prepare("INSERT INTO PERSONNEL (id_p, password_p, email_p, nom_p,dateemb_p, salaire_p) "
                     "VALUES (:id_p, :password_p, :email_p, :nom_p,:dateemb_p, :salaire_p)");

       query.bindValue(":id_p", id_p);
       query.bindValue(":password_p", password_p);
       query.bindValue(":email_p", email_p);
       query.bindValue(":nom_p", nom_p);
       query.bindValue(":dateemb_p", dateemb_p);
       query.bindValue(":salaire_p", salaire_p);

       return query.exec();
   }


    QSqlQueryModel* Pers::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * from PERSONNEL");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" password"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" email"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("date"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("salaire"));



        return model;
    }
    bool Pers::supprimer(int id_p)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM PERSONNEL WHERE id_p = :id_p");
        query.bindValue(":id_p", id_p);

        if (query.exec()) {
            // Check if any rows were affected (record was deleted)
            if (query.numRowsAffected() > 0) {
                return true;
            }
        }

        return false;
    }
    bool Pers::checkIfPersExists(int id_p)
    {
        QSqlQuery query;
        query.prepare("SELECT id_p FROM PERSONNEL WHERE id_p = :id_p");
        query.bindValue(":id_p", id_p);

        if (query.exec() && query.next()) {
            return true;
        } else {
            return false;
        }
    }

    bool Pers::modifierE(int id_p)
    {
        QSqlQuery query;
        query.prepare("UPDATE PERSONNEL SET password_p=:password_p, email_p=:email_p, nom_p=:nom_p, dateemb_p=:dateemb_p, salaire_p=:salaire_p WHERE id_p=:id_p");

        query.bindValue(":id_p", id_p);
        query.bindValue(":password_p", password_p);
        query.bindValue(":email_p", email_p);
        query.bindValue(":nom_p", nom_p);
        query.bindValue(":dateemb_p", dateemb_p);
        query.bindValue(":salaire_p", salaire_p);

        return query.exec();
    }



#include "client.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QIntValidator>
#include<QSqlError>
#include<QString>
#include<QComboBox>
#include <QCoreApplication>
Client::Client()
{
     id_c= 0;
     nom_c="";
     adresse_c="";
     email_c="";
     telephone_c= 0;
     id_t=0;
     budget_c=0;

    }
     Client::Client (int  id_c,QString nom_c,QString adresse_c,QString email_c,int  telephone_c,int budget_c)
      {
        this->id_c  = id_c  ;
      this->nom_c=nom_c ;
         this->adresse_c=adresse_c ;
         this->email_c = email_c;
         this->telephone_c = telephone_c ;
         this->budget_c = budget_c ;

     }
   int Client::getid_c(){return id_c ;}
     QString Client::getnom_c(){return nom_c ;}
   QString Client::getadresse_c(){return adresse_c ;}
    QString Client::getemail_c(){return email_c;}
    int Client::gettelephone_c(){return telephone_c ;}
    int Client::getbudget_c(){return budget_c;}




    void Client:: setid_c(int id){this->id_c =id_c;}
   void Client:: setnom_c(QString nom_c ){this->nom_c =nom_c ;}
   void Client:: setadresse_c(QString adresse_c ){this->adresse_c=adresse_c ;}
   void Client:: setemail_c(QString email_c ){this->email_c=email_c ;}
   void Client:: settelephone_c(int telephone_c ){this->telephone_c =telephone_c;}
   void Client:: setbudget_c(int budget_c ){this->budget_c=budget_c ;}


   bool Client::ajouter()
   {
       QSqlQuery query;
       query.prepare("INSERT INTO CLIENT (id_c, nom_c, adresse_c, email_c, telephone_c, id_t, budget_c) "
                     "VALUES (:id_c, :nom_c, :adresse_c, :email_c, :telephone_c, :id_t, :budget_c)");




       query.bindValue(":id_c", id_c);
       query.bindValue(":nom_c", nom_c);
       query.bindValue(":adresse_c", adresse_c);
       query.bindValue(":email_c", email_c);
       query.bindValue(":telephone_c", telephone_c);
       query.bindValue(":id_t", id_t);
       query.bindValue(":budget_c", budget_c);

       return query.exec();
   }

    QSqlQueryModel* Client::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * from CLIENT");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" nom "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" adresse"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("email"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));




        return model;
    }
    bool Client::supprimer(int  id_c)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM CLIENT WHERE id_c = :id_c");
        query.bindValue(":id_c", id_c);
        return query.exec();
    }
    bool Client::checkIfClientExists(int id_c)
    {
        QSqlQuery query;
        query.prepare("SELECT id_t FROM CLIENT where id_c=:id_c");
        query.bindValue(":id_c", id_c);
        if (query.exec() && query.next()) {
            return true;
        } else {
            return false;
        }
    }
    bool Client::modifierE(int id_c)
    {
        QSqlQuery query;
        query.prepare("UPDATE CLIENT SET nom_c=:nom_c, adresse_c=:adresse_c, email_c=:email_c, telephone_c=:telephone_c, id_t=:id_t, budget_c=:budget_c WHERE id_c=:id_c");
        query.bindValue(":id_c", id_c);
        query.bindValue(":nom_c", nom_c);
        query.bindValue(":adresse_c", adresse_c);
        query.bindValue(":email_c", email_c);
        query.bindValue(":telephone_c", telephone_c);
        query.bindValue(":id_t", id_t);
        query.bindValue(":budget_c", budget_c);

        if (!query.exec()) {
            qDebug() << "Error during update:" << query.lastError().text();
            qDebug() << "Query:" << query.lastQuery();
        } else {
            qDebug() << "Update successful!";
        return true;
    }
     }



    int Client::getid_t() { return id_t; }
    void Client::setid_t(int id_t) { this->id_t = id_t; }

#include "transaction.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QIntValidator>
#include<QSqlError>
#include<QString>
#include<QComboBox>
#include <QCoreApplication>
Transaction::Transaction()
{
    id_t = 0;
    montant_t = 0;
   date_t = 0;
     statutpaiment_t="";
     type_t="";

    }
     Transaction::Transaction (int  id_t,int  montant_t ,int date_t,QString statutpaiment_t,QString type_t)
      {
        this->id_t  = id_t  ;
      this->montant_t=montant_t ;
         this->date_t=date_t ;
         this->statutpaiment_t = statutpaiment_t;
         this->type_t = type_t ;

     }
   int Transaction::getid_t(){return id_t ;}
    int Transaction::getmontant_t(){return montant_t ;}
     int Transaction::getdate_t(){return date_t ;}
     QString Transaction::getstatutpaiment_t(){return statutpaiment_t ;}
   QString Transaction::gettype_t(){return type_t ;}




    void Transaction:: setid_t(int id_t ){this->id_t =id_t ;}
    void Transaction:: setmontant_t(int montant_t ){this->montant_t =montant_t ;}
  void Transaction:: setdate_t(int date_t){this->date_t =date_t ;}
   void Transaction:: setstatutpaiment_t(QString statutpaiment_t ){this->statutpaiment_t =statutpaiment_t ;}
   void Transaction:: settype_t(QString type_t ){this->type_t =type_t ;}


   bool Transaction::ajouter()
   {
       QSqlQuery query;
       query.prepare("INSERT INTO TRANSACTION (id_t, montant_t, date_t, statutpaiment_t, type_t) "
                     "VALUES (:id_t, :montant_t, :date_t, :statutpaiment_t, :type_t)");

       query.bindValue(":id_t", id_t);
       query.bindValue(":montant_t", montant_t);
       query.bindValue(":date_t", date_t);
       query.bindValue(":statutpaiment_t", statutpaiment_t);
       query.bindValue(":type_t", type_t);

       return query.exec();
   }


    QSqlQueryModel* Transaction::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * from TRANSACTION");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" montant "));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr(" date"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("statutpaiment"));
            model->setHeaderData(4, Qt::Horizontal, QObject::tr("type"));



        return model;
    }
    bool Transaction::supprimer(int  id_t)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM TRANSACTION WHERE id_t = :id_t");
        query.bindValue(":id_t", id_t);
        return query.exec();
    }
    bool Transaction::checkIfTransExists(int id_t)
    {
        QSqlQuery query;
        query.prepare("SELECT id_t FROM TRANSACTION where id_t=:id_t");
        query.bindValue(":id_t", id_t);
        if (query.exec() && query.next()) {
            return true;
        } else {
            return false;
        }
    }
    bool Transaction::modifierE(int id_t)
    {
        QSqlQuery query;
        query.prepare("UPDATE TRANSACTION SET montant_t=:montant_t, date_t=:date_t, statutpaiment_t=:statutpaiment_t, type_t=:type_t WHERE id_t=:id_t");

        query.bindValue(":id_t", id_t);
        query.bindValue(":montant_t", montant_t);
        query.bindValue(":date_t", date_t);
        query.bindValue(":statutpaiment_t", statutpaiment_t);
        query.bindValue(":type_t", type_t);

        if (!query.exec()) {
            qDebug() << "Error during update:" << query.lastError().text();
            qDebug() << "Query: " << query.lastQuery();
            return false;
        }

        qDebug() << "Update successful!";
        return true;
    }




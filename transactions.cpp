#include "transactions.h"
#include <QSqlQuery>
#include <QDebug>
#include<QSqlError>
#include <QMessageBox>

    transactions::transactions()
    {
        id_transaction=0;
        montant="";
        date_transaction="";
        statut_paiement="";
        type_transaction="";
        accompte=0;
        etat_produit="";
    }
    transactions::transactions(int id_transaction, QString montant ,QString date_transaction,QString statut_paiement,QString type_transaction,int accompte,QString etat_produit)
    {
        this->id_transaction=id_transaction;
        this->montant=montant;
        this->date_transaction=date_transaction;
        this->statut_paiement=statut_paiement;
        this->type_transaction=type_transaction;
        this->accompte=accompte;
        this->etat_produit=etat_produit;

    }

    bool transactions::ajouter()
    {
        QSqlQuery query;
        query.prepare("INSERT INTO transactions (montant, date_transaction, statut_paiement, "
                      "type_transaction, accompte, etat_produit) "
                      "VALUES (:montant, :date_transaction, :statut_paiement, "
                      ":type_transaction, :accompte, :etat_produit)");

        // Bind each variable correctly to the prepared statement parameters
        query.bindValue(":montant", montant);
        query.bindValue(":date_transaction", date_transaction);
        query.bindValue(":statut_paiement", statut_paiement);
        query.bindValue(":type_transaction", type_transaction);
        query.bindValue(":accompte", accompte);
        query.bindValue(":etat_produit", etat_produit);

        return query.exec();
    }



    QSqlQueryModel * transactions::afficher()
    {
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from transactions");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_transaction"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("montant"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_transaction"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("statut_paiement"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_transaction"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("accompte"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("etat_produit"));
        return model;
    }



    QSqlQueryModel * transactions::affichers()
    {
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from transactions");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_transaction"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_transaction"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("type_transaction"));
        return model;
    }

    bool  supprimer(int id_transaction) {
           QSqlQuery query;
           query.prepare("DELETE FROM transactions WHERE id_transaction = :id_transaction");
           query.bindValue(":id_transaction", id_transaction);
           if (!query.exec()) {
               qDebug() << "Delete failed: " ; // Detailed error message
               return false;
           }
           return true;
       }



    bool transactions::modifier(int id_transaction,QString montant,QString date_transaction,QString statut_paiement,QString type_transaction,int accompte,QString etat_produit)
    {
        QSqlQuery query;
        query.prepare("UPDATE transactions set id_transaction=:id_transaction,montant=:montant,date_transaction=:date_transaction,statut_paiement=:statut_paiement,type_transaction=:type_transaction,accompte=:accompte ,etat_produit=:etat_produit where id_transaction= :id_transaction ");
        query.bindValue(":id_transaction",id_transaction);
        query.bindValue(":montant",montant);
        query.bindValue(":date_transaction",date_transaction);
        query.bindValue(":statut_paiement",statut_paiement);
        query.bindValue(":type_transaction",type_transaction);
        query.bindValue(":accompte",accompte);
       query.bindValue(":etat_produit",etat_produit);
        return query.exec();
    }


    QSqlQueryModel* transactions::rechercher(QString A)
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM transactions WHERE statut_paiement LIKE '%" + A + "%'");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id_transaction"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("montant"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_transaction"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("statut_paiement"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("type_transaction"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("accompte"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("etat_produit"));

        return model;
    }

    QSqlQueryModel* transactions::afficher_tri_date()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM transactions ORDER BY date");
        return model;
    }
    QSqlQueryModel* transactions::afficher_tri_montant() {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM transactions ORDER BY montant");
        return model;
    }
     bool transactions:: supprimer(int  id_transaction)
     {
         QSqlQuery query;
                QString res=QString::number(id_transaction);
                query.prepare("DELETE FROM transactions WHERE id_transaction = :id_transaction");
                query.bindValue(":id_transaction", res);

                return query.exec();
     }
     QString transactions::getTotalTransactions() {
         QSqlQuery query;
         query.prepare("SELECT COUNT(*) as num_transactions FROM transactions");
         if (!query.exec()) {
             qDebug() << "Error executing query:" << query.lastError().text();
             return QString();
         }

         if (query.next()) {
             int numTransactions = query.value("num_transactions").toInt();
             return QString::number(numTransactions);
         }

         return "N/A";
     }

     QSqlQuery transactions::rechercherParID(int id) {
         QSqlQuery query;
             query.prepare("SELECT * FROM transactions WHERE id_transaction = :id");
             query.bindValue(":id", id);
             query.exec();

             if(query.size() == 0) {
                 qDebug() << "Aucun enregistrement trouvé pour l'ID :" << id;
             }

             return query;
     }

#include "transactions.h"
#include <QSqlQuery>
#include <QDebug>
transactions::transactions() {

}
    transactions::transactions(int id_transaction, QString montant ,QString date_transactions,QString statut_paiement,QString type_transaction)
    {
        this->id_transaction=id_transaction;
        this->montant=montant;
        this->date_transactions=date_transactions;
        this->statut_paiement=statut_paiement;
        this->type_transaction=type_transaction;

    }

    bool transactions::ajouter()
    {
        QSqlQuery query;
        query.prepare("INSERT INTO TABLE1 VALUES(:id_transaction,:montant,:date_transactions,:statut_paiement,:type_transaction)");
        query.bindValue(":id_transaction",id_transaction);
        query.bindValue(":montant",montant);
        query.bindValue(":date_transactions",date_transactions);
        query.bindValue(":statut_paiement",statut_paiement);
        query.bindValue(":type_transaction",type_transaction);
        return query.exec();
    }


    QSqlQueryModel * transactions::afficher()
    {
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from TABLE1");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_transaction"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("montant"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("date_transactions"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("statut_paiement"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("type_transaction"));
        return model;
    }



    QSqlQueryModel * transactions::affichers()
    {
        QSqlQueryModel * model=new QSqlQueryModel();

        model->setQuery("select * from TABLE1");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_transaction"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("date_transactions"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("DOMAINE"));
        return model;
    }

    bool supprimer(int id_transaction) {
           QSqlQuery query;
           query.prepare("DELETE FROM TABLE1 WHERE id_transaction = :id_transaction");
           query.bindValue(":id_transaction", id_transaction);
           if (!query.exec()) {
               qDebug() << "Delete failed: " ; // Detailed error message
               return false;
           }
           return true;
       }



    bool transactions::modifier(int id_transaction,QString montant,QString date_transactions,QString statut_paiement,QString type_transaction)
    {
        QSqlQuery query;
        query.prepare("UPDATE TABLE1 set id_transaction=:id_transaction,montant=:montant,date_transactions=:date_transactions,statut_paiement=:statut_paiement,type_transaction=:type_transaction where id_transaction= :id_transaction ");
        query.bindValue(":id_transaction",id_transaction);
        query.bindValue(":montant",montant);
        query.bindValue(":date_transactions",date_transactions);
        query.bindValue(":statut_paiement",statut_paiement);
        query.bindValue(":type_transaction",type_transaction);

        return query.exec();
    }




#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class transactions
{

private:
    int id_transaction;
    QString montant;
    QString  date_transactions;
    QString  statut_paiement;
    QString  type_transaction;

public:
    transactions();
    transactions(int,QString,QString,QString,QString);

    void setid_transaction(int n);
    void setmontant(QString n);
    void setdate_transactions(QString n);
    void setstatut_paiement(QString n);
    void settype_transaction(QString n);

    QString get_id_transaction();
    QString get_montant();
    QString get_date_transactions();
    QString get_statut_paiement();
    QString get_type_transaction();

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * affichers();
    bool supprimer(int  id_transaction);
    bool modifier(int,QString,QString,QString,QString);



};

#endif // TRANSACTIONS_H

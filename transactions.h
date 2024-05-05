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
    QString  date_transaction;
    QString  statut_paiement;
    QString  type_transaction;
    int accompte;
    QString etat_produit;


public:
    transactions();
    transactions(int,QString,QString,QString,QString, int, QString);


    void setid_transaction(int n);
    void setmontant(QString n);
    void setdate_transaction(QString n);
    void setstatut_paiement(QString n);
    void settype_transaction(QString n);
    void setaccompte(int n);
    void setetat_produit(QString n);



    QString get_id_transaction();
    QString get_montant();
    QString get_date_transaction();
    QString get_statut_paiement();
    QString get_type_transaction();
    int get_accompte();
    QString get_etat_produit();



    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * affichers();
    bool supprimer(int  id_transaction);
    bool modifier(int,QString,QString,QString,QString,int,QString);
    QSqlQueryModel* afficher_tri_date();
    QSqlQueryModel* afficher_tri_montant();
    QSqlQueryModel* rechercher(QString);
    QString getTotalTransactions();
    QSqlQuery rechercherParID(int );

};

#endif // TRANSACTIONS_H

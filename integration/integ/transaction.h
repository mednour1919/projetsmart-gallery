#ifndef TRANSACTION_H
#define TRANSACTION_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QDate>

class Transaction
{
public:
    Transaction();
    Transaction(int,int,int,QString,QString);

int getid_t();
int getmontant_t();
int getdate_t();
QString getstatutpaiment_t();
QString gettype_t();

void setid_t(int);
void setmontant_t(int);
void setdate_t(int);
void setstatutpaiment_t(QString);
void settype_t(QString);

bool ajouter();
QSqlQueryModel* afficher ();
bool supprimer (int);
bool modifierE(int);
 bool checkIfTransExists(int);
private:
    int id_t, montant_t, date_t ;
    QString  statutpaiment_t,type_t ;

};

#endif // TRANSACTION_H

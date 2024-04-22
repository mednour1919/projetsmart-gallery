#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QDate>

class Client
{
public:
    Client();
    Client(int,QString,QString,QString,int,int);

int getid_c();
QString getnom_c();
QString getadresse_c();
QString getemail_c();
int gettelephone_c();
int getbudget_c();

void setid_c(int);
void setnom_c(QString);
void setadresse_c(QString);
void setemail_c(QString);
void settelephone_c(int);
int getid_t();
void setbudget_c(int);
void setid_t(int id_t);
bool ajouter();
QSqlQueryModel* afficher ();
bool supprimer (int);
bool modifierE(int);
 bool checkIfClientExists(int);
private:
    int id_c, telephone_c , id_t,budget_c;
    QString  nom_c, adresse_c ,email_c  ;

};
#endif // CLIENT_H

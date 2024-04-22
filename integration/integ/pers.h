#ifndef PERS_H
#define PERS_H

#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QDate>

class Pers
{
public:
    Pers();
    Pers(int,QString,QString,QString,QString,int);

int getid_p();
QString getemail_p();
QString getpassword_p();
QString getnom_p();
QString getdateemb_p();
int getsalaire_p();

void setid_p(int);
void setemail_p(QString);
void setpassword_p(QString);
void setnom_p(QString);
void setdateemb_p(QString);
void setsalaire_p(int);

bool ajouter();
QSqlQueryModel* afficher ();
bool supprimer (int);
bool modifierE(int);
 bool checkIfPersExists(int);
private:
    int id_p, salaire_p ;
    QString  email_p, password_p ,nom_p, dateemb_p ;

};
#endif // PERS_H

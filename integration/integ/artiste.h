#ifndef ARTISTE_H
#define ARTISTE_H

#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QDate>

class Artiste
{
public:
    Artiste();
    Artiste(QString,QString,QString,QString,QString);


QString getnom_a();
QString getstatus_a();
QString getoeuvresmaj_a();
QString getemail_a();
QString getstyleart_a();

void setnom_a(QString);
void setstatus_a(QString);
void setoeuvresmaj_a(QString);
void setemail_a(QString);
void setstyleart_a(QString);

bool ajouter();
QSqlQueryModel* afficher ();
bool supprimer (QString);
bool modifierE(QString);
 bool checkIfArtisteExists(QString);
private:
    QString  nom_a, status_a ,oeuvresmaj_a,email_a,styleart_a;

};

#endif // ARTISTE_H

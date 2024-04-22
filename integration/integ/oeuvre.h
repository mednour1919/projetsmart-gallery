#ifndef OEUVRE_H
#define OEUVRE_H


#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QDate>

class Oeuvre
{
public:
    Oeuvre();
    Oeuvre(QString,QString,int,QString);


QString getnom_o();
QString getdate_o();
int getprix_o();
QString getdiscription_o();

void setnom_o(QString);
void setdate_o(QString);
void setprix_o(int);
void setdiscription_o(QString);
QString getnom_a();
void setnom_a(QString nom_a);

bool ajouter();
QSqlQueryModel* afficher ();
bool supprimer (QString);
bool modifierE(QString);
 bool checkIfOeuvreExists(QString);
private:
 int prix_o;
    QString nom_o, date_o ,discription_o, nom_a;

};

#endif // OEUVRE_H

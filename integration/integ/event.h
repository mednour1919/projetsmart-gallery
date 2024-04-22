#ifndef EVENT_H
#define EVENT_H
#include<QString>
#include<QDate>
#include<QSqlQueryModel>
#include<QDate>

class Event
{
public:
    Event();
    Event(QString,QString,QString,int,QString);
    QSqlQueryModel* sortByParticipantsAsc();
       QSqlQueryModel* sortByParticipantsDesc();
       QSqlQueryModel* retrieveCLIENTData();
        QSqlQueryModel *retrieveHighBudgetClients();

QString gettitre_e();
QString getdated_e();
QString getdatef_e();
int getnb_e();
QString getlocation_e();

void settitre_e(QString);
void setdated_e(QString);
void setdatef_e(QString);
void setnb_e(int);
void setlocation_e(QString);
QString getnom_a();
void setnom_a(QString nom_a);
bool ajouter();
QSqlQueryModel* afficher ();
bool supprimer (QString);
bool modifierE(QString);
 bool checkIfeventExists(QString);
private:
    int nb_e ;
    QString  titre_e,dated_e,datef_e,location_e,nom_a;

};

#endif // EVENT_H

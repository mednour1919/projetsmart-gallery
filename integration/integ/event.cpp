#include "event.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QObject>
#include <QIntValidator>
#include<QSqlError>
#include<QString>
#include<QComboBox>
#include <QCoreApplication>
QSqlQueryModel* Event::sortByParticipantsAsc()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement ORDER BY nb_e ASC");
    return model;
}

QSqlQueryModel* Event::sortByParticipantsDesc()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM evenement ORDER BY nb_e DESC");
    return model;
}
Event::Event()
{
    titre_e="";
     dated_e ="";
     datef_e="";
       nb_e = 0;
     location_e="";
     nom_a="";

    }
     Event::Event (QString  titre_e,QString dated_e,QString datef_e,int nb_e,QString location_e)
      {
        this->titre_e = titre_e ;
         this->dated_e=datef_e ;
         this->datef_e = datef_e;
         this->nb_e = nb_e ;
          this-> location_e =  location_e ;
     }
    QString Event::gettitre_e(){return titre_e ;}
     QString Event::getdated_e(){return dated_e ;}
     QString Event::getdatef_e(){return datef_e ;}
    int Event::getnb_e(){return nb_e ;}
    QString Event::getlocation_e(){return location_e ;}



    void Event:: settitre_e(QString titre_e ){this->titre_e =titre_e ;}
  void Event:: setdated_e(QString dated_e ){this->dated_e =dated_e ;}
   void Event:: setdatef_e(QString datef_e ){this->datef_e =datef_e ;}
 void Event:: setnb_e(int nb_e ){this->nb_e =nb_e ;}
void Event:: setlocation_e(QString location_e ){this->location_e =location_e ;}

bool Event::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO evenement (titre_e, dated_e, datef_e, nb_e, location_e, nom_a) "
                  "VALUES (:titre_e, :dated_e, :datef_e, :nb_e, :location_e, :nom_a)");

    query.bindValue(":titre_e", titre_e);
    query.bindValue(":dated_e", dated_e);
    query.bindValue(":datef_e", datef_e);
    query.bindValue(":nb_e", nb_e);
    query.bindValue(":location_e", location_e);
    query.bindValue(":nom_a", nom_a);

    return query.exec();
}


    QSqlQueryModel* Event::afficher()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("select * from evenement");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("titre"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr(" dated"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("datef"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("nb"));
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("location"));


        return model;
    }
    bool Event::supprimer(QString titre_e)
    {
        QSqlQuery query;
        query.prepare("DELETE FROM evenement WHERE titre_e = :titre_e");
        query.bindValue(":titre_e", titre_e);
        return query.exec();
    }
    bool Event::checkIfeventExists(QString titre_e)
    {
        QSqlQuery query;
        query.prepare("SELECT titre_e FROM evenement where titre_e=:titre_e");
        query.bindValue(":titre_e", titre_e);
        if (query.exec() && query.next()) {
            return true;
        } else {
            return false;
        }
    }
    bool Event::modifierE(QString titre_e)
     {
        QSqlQuery query;
              query.prepare("UPDATE evenement SET  dated_e=:dated_e,datef_e=:datef_e, nb_e=:nb_e,location_e=:location_e,nom_a=:nom_a WHERE titre_e=:titre_e  " );
              query.bindValue(":titre_e", QString(titre_e));
             query.bindValue(":dated_e",dated_e);
               query.bindValue(":datef_e",datef_e);
               query.bindValue(":nb_e",nb_e);
                  query.bindValue(":location_e",location_e);
                   query.bindValue(":nom_a",nom_a);
              return  query.exec();



     }

    QString Event::getnom_a() { return nom_a; }
    void Event::setnom_a(QString nom_a) { this->nom_a = nom_a; }
    QSqlQueryModel* Event::retrieveCLIENTData()
    {
        QSqlQueryModel* model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM CLIENT");
        return model;
    }
    QSqlQueryModel *Event::retrieveHighBudgetClients()
    {
        QSqlQueryModel *model = new QSqlQueryModel();
        QSqlQuery query;
        query.prepare("SELECT * FROM CLIENT WHERE BUDGET_C > 2000"); // Assuming the column name for budget is "BUDGET_C"
        if (!query.exec()) {
            qDebug() << "Error retrieving high budget clients:" << query.lastError().text();
            delete model;
            return nullptr;
        }
        model->setQuery(query);
        return model;
    }

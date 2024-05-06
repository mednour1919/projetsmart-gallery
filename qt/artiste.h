#ifndef ARTISTE_H
#define ARTISTE_H

#include <QString>
#include <QSqlQueryModel>

class Artiste
{
public:
    Artiste(){}
    Artiste(int,QString, QString, QString, QString, QString);
    int get_ida(){return ida;}
    void setid(int d){ida=d;}

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
    QSqlQueryModel* afficher();
    bool supprimer(int ida);
    bool modifierE(int ida);
    bool checkIfArtisteExists(QString);

    QSqlQueryModel* afficher1();
    int exporterPDF(QAbstractItemModel* model);
    QSqlQueryModel* rechercher(const QString& recherche) ;


private:
    int ida;
    QString nom_a, status_a, oeuvresmaj_a, email_a, styleart_a;
};

#endif // ARTISTE_H

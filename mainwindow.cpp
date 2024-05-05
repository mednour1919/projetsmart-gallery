#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "transactions.h"
#include <QSqlQuery>
#include <QDebug>
#include <QPushButton>
#include <QLabel>
 #include <QScrollArea>
#include <QtWidgets>
#include <QPrinter>
#include <QPainter>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextDocument>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
        //le slot update_label suite à la reception du signal readyRead (reception des données).


        connect(ui->updatetableView, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(on_updatetableView_doubleClicked(const QModelIndex&)));
        connect(ui->tableView_2, SIGNAL(doubleClicked(const QModelIndex&)), this, SLOT(on_tableView_2_doubleClicked(const QModelIndex&)));
         ui->tableView_3->setModel(Tr.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
        ui->updatetableView->setModel(Tr.afficher());
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
        ui->tableView_2->setModel(Tr.afficher());
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
        ui->tableView_3->setModel(Tr.afficher());
}
void MainWindow::on_valider_clicked()
{
    //int id_projet = 0;
        QString montant= ui->montant->text();
        QString date_transaction = ui->date_transaction->text();
        QString statut_paiement = ui->statut_paiement->text();
        QString type_transaction = ui->type_transaction->text();
        int accompte = ui->accompte->text().toInt();
        QString etat_produit =ui->etat_produit->text();

        transactions *T=new transactions(0, montant, date_transaction, statut_paiement,type_transaction,accompte,etat_produit);

        bool test = T->ajouter();
        if (test)
        {
            ui->montant->clear();
            ui->date_transaction->clear();
            ui->statut_paiement->clear();
            ui->type_transaction->clear();
            ui->accompte->clear();
            ui->etat_produit->clear();

            ui->stackedWidget->setCurrentIndex(0);
            ui->tableView_3->setModel(Tr.afficher());
            ui->tableView_2->setModel(Tr.afficher());
            ui->updatetableView->setModel(Tr.affichers());
            QMessageBox::information(nullptr, QObject::tr("database is open"),
                                     QObject::tr("connection successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                  QObject::tr("connection failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_quitter_clicked()
{
    ui->id_transaction->setText("");
        ui->montant->setText("");
        ui->date_transaction->setText("");
        ui->statut_paiement->setText("");
        ui->type_transaction->setText("");
        ui->accompte->setText("");
        ui->etat_produit->setText("");


}


void MainWindow::on_valider_2_clicked()
{
         int id_transaction= ui->id_transaction->text().toInt();
       // int id_projet= ui->id_projet_4->text().toInt();
        QString montant=ui->montant_2->text();
        QString date_transaction=ui->date_transaction_2->text();
        QString statut_paiement=ui->statut_paiement_2->text();
        QString type_transaction=ui->type_transaction_2->text();
        int accompte= ui->accompte_2->text().toInt();
         QString etat_produit=ui->etat_produit_2->text();

        bool test=Tr.modifier(id_transaction,/*id_projet*/montant,date_transaction,statut_paiement, type_transaction,accompte,etat_produit);

        if (test)
        {
            ui->tableView_3->setModel(Tr.afficher());//refresh
            ui->tableView_2->setModel(Tr.afficher());//refresh
            ui->updatetableView->setModel(Tr.affichers());//refresh
            QMessageBox::information(nullptr, QObject::tr("Modifier une transaction"),
                        QObject::tr("transaction modifiée.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Modifier une transaction"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_quitter_2_clicked()
{
       ui->id_transaction->setText("");
        ui->montant_2->setText("");
        ui->date_transaction_2->setText("");
        ui->statut_paiement_2->setText("");
        ui->type_transaction_2->setText("");
        ui->accompte_2->setText("");
        ui->etat_produit_2->setText("");
}

void MainWindow::on_suprimer_clicked()
{
    qDebug() << "Attempting to delete etude with id_transactions: " << id_transaction; // Debug message before deletion
        bool suppressionReussie = Tr.supprimer(id_transaction);
        if (suppressionReussie) {
            // Refresh the table view
            // Assuming a.afficher() returns a model that can be used to refresh the view
            ui->tableView_2->setModel(Tr.afficher());

            QMessageBox::information(this, "Success", "transaction deleted successfully.");
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete Etude.");
        }
}

void MainWindow::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
        id_transaction = ui->tableView_2->model()->index(row, 0).data().toInt();
        qDebug() << "id_transactions selected: " << id_transaction; // Debug message to confirm CIN is selected
}

void MainWindow::on_updatetableView_doubleClicked(const QModelIndex &index)
{
    // Check if the index is valid
     if (!index.isValid()) {
            // Handle the invalid index if necessary, e.g., show an error message
            return;
        }

        // Define the column indices based on your table's actual structure
        const int id_transaction_COLUMN = 0;

        const int montant_COLUMN = 1;
        const int date_transaction_COLUMN = 2;
        const int statut_paiement_COLUMN = 3;
        const int type_transaction_COLUMN = 4;
        const int accompte_COLUMN =5;
        const int etat_produit_COLUMN =6;

        // Retrieve the artist's details from the selected row in updateview_2.
        int id_transaction = index.sibling(index.row(), id_transaction_COLUMN).data().toInt();

        QString montant = index.sibling(index.row(), montant_COLUMN).data().toString();
        QString date_transaction = index.sibling(index.row(), date_transaction_COLUMN).data().toString();
        QString statut_paiement = index.sibling(index.row(), statut_paiement_COLUMN).data().toString();
        QString type_transaction= index.sibling(index.row(), type_transaction_COLUMN).data().toString();
        int accompte = index.sibling(index.row(), accompte_COLUMN).data().toInt();
        QString etat_produit = index.sibling(index.row(), etat_produit_COLUMN).data().toString();

        // Fill the input fields with the retrieved data.
        ui->id_transaction->setText(QString::number(id_transaction));

        ui->montant_2->setText(montant);
        ui->date_transaction_2->setText(date_transaction);
        ui->statut_paiement_2->setText(statut_paiement);
        ui->type_transaction_2->setText(type_transaction);
        ui->accompte_2->setText(QString::number(accompte));
        ui->etat_produit_2->setText(etat_produit);



        // Now the user can modify the data in the input fields.
}





void MainWindow::on_comboBox_activated(int index)
{
    switch(index) {
                    case 1: // Tri par montant
                        ui->tableView_3->setModel(Tr.afficher_tri_montant());
                        break;
                    case 2: // Tri par date


                        ui->tableView_3->setModel(Tr.afficher_tri_date());
                        break;

                    default:
                        break;
                }
}

void MainWindow::on_searchTextBox_textChanged(const QString &arg1)
{
    QString searchQuery = "%" + arg1 + "%";
              QSqlQueryModel* filteredModel = Tr.rechercher(searchQuery);
              ui->tableView_3->setModel(filteredModel);
}




void MainWindow::on_stackedWidget_currentChanged(int arg1)
{
    if (arg1==0)
    {
        transactions t; ui->label_13->setText(t.getTotalTransactions());
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    QSqlQueryModel *model = qobject_cast<QSqlQueryModel*>(ui->tableView_3->model());

        if (model) {
            QString content;
            //header
            for (int col = 0; col < model->columnCount(); ++col) {

                 content += model->headerData(col, Qt::Horizontal).toString() + "\t ";

                    }
            content += "\n";
            // Parcourez les données du modèle et ajoutez-les au contenu
            for (int row = 0; row < model->rowCount(); ++row) {
                for (int col = 0; col < model->columnCount(); ++col) {
                    content += model->data(model->index(row, col)).toString() + "\t";
                }
                content += "\n";
            }

            // Créez un objet QTextDocument et définissez son contenu
            QTextDocument document;
            document.setPlainText(content);

            // Créez un dialogue pour sélectionner l'emplacement de sauvegarde du PDF.
            QString fileName = QFileDialog::getSaveFileName(this, "Exporter en PDF", "info", "Fichiers PDF (*.pdf)");

            if (!fileName.isEmpty()) {
                // Créez un objet QPrinter pour générer le PDF.
                QPrinter printer;
                printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setOutputFileName(fileName);

                // Imprimez le document sur le PDF.
                document.print(&printer);

                // Affichez un message à l'utilisateur pour confirmer l'exportation réussie.
                QMessageBox::information(this, "Export PDF", "Le PDF a été créé avec succès.");
            }
        }
}

void MainWindow::on_PLUS_clicked()
{
    A.write_to_arduino("2");   //envoyer 2 à arduino
}

void MainWindow::on_MOINS_clicked()
{
    A.write_to_arduino("3");  //envoyer 3 à arduino
}

void MainWindow::on_ON_clicked()
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
}

void MainWindow::on_OFF_clicked()
{
    A.write_to_arduino("0");  //envoyer 0 à arduino
}
void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_18->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_18->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}


void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_reserver_clicked()
{
    qDebug() << "Button clicked";
    int id_prod = ui->id_prod->text().toInt();
    int accompte = ui->accompte_pr->text().toInt();

    QSqlQuery query = Tr.rechercherParID(id_prod);
    if (!query.next()) {
        qDebug() << "Requête sans résultats pour l'ID :" << id_prod;
        QMessageBox::critical(this, "Error", "Identifiant de transaction non trouvé.");
        return;
    }

    QString montant = query.value("montant").toString();
    int montantInt = montant.toInt();
    QString etat_produit = query.value("etat_produit").toString();
    qDebug() << "Montant trouvé :" << montantInt << "Pour accompte :" << accompte << ", État du produit :" << etat_produit;

    if (etat_produit == "non_disponible") {
        QMessageBox::information(this, "Information", "Non, ce produit est déjà réservé.");
        return;
    }

    if (accompte >= montantInt / 5) {
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE transactions SET etat_produit = 'non_disponible', accompte = :accompte WHERE id_transaction = :id");
        updateQuery.bindValue(":accompte", accompte);
        updateQuery.bindValue(":id", id_prod);

        if (updateQuery.exec()) {
            QMessageBox::information(this, "Success", "Produit réservé et accompte enregistré.");
        } else {
            QMessageBox::critical(this, "Error", "Failed to update the database.");
        }
    } else {
        QMessageBox::critical(this, "Error", "L'accompte doit être supérieur au 1/5 du montant.");
    }
}


void MainWindow::on_pushButton_7_clicked()
{


}

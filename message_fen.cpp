#include "message_fen.h"
#include "ui_message_fen.h"
#include "QString"
#include "connexion_fen.h"
#include "Users.h"
#include "QSqlQuery"
#include "iostream"
#include "QSqlError"
#include "QMessageBox"

QString userid ;
QString userid2;


message_fen::message_fen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::message_fen)
{
    ui->setupUi(this);
}

message_fen::~message_fen()
{
    delete ui;
}

//fenetre parent fenetre fille
void message_fen::setVar(QString acc)
{
    ui->id_label->setText(acc);
}

//deconnection
void message_fen::on_pushButton_2_clicked()
{
   connexion_fen *f = new connexion_fen();
   f->show();
   this->close();
}

//boutton pour afficher la liste des amis
void message_fen::on_pushButton_4_clicked()
{
    QString userid = ui->id_label->text();
    QSqlQuery query;
    ui->liste_amis->clear();
    query.exec("SELECT user_id2 FROM amis WHERE user_id1 = '"+userid+"'; " );
    // query.exec("SELECT users.user_id, users.user_pseudo FROM users WHERE user_id IN (SELECT user_id2 FROM amis WHERE user_id1 = '"+userid+"');");//afficher la liste d'amis dans la table users

        while(query.next())
         {
                 ui->liste_amis->addItem(query.value(0).toString());
        }
}

//afficher la liste d'invitation
void message_fen::on_pushButton_5_clicked()
{
    QSqlQuery query;
    userid = ui->id_label->text();
    ui->liste_invitation->clear();
    query.exec("SELECT id_emetteur_invitation FROM invitations WHERE invitation_statut = 0 AND  id_receveur_invitation = '"+userid+"'; " );

//    if(!query.next())
//    {
//         QMessageBox::critical(0, QObject::tr("Erreur de connexion"),query.lastError().text());
//    }

    while(query.next())
     {
             ui->liste_invitation->addItem(query.value(0).toString());
     }
}

//afficher la liste des differents messages
void message_fen::on_pushButton_3_clicked()
{
    if(ui->listMessage->count()==0)
    {
        QMessageBox::information(0,"Message", "Votre messagerie est vide. Veuillez cliquer sur un ami pour commencer la communication.");
    }
    else
    {

        userid = ui->id_label->text();
        userid2 = ui->liste_amis->currentItem()->text();
        QSqlQuery query;
        query.exec(" SELECT * FROM messages WHERE id_emetteur_message='"+userid+"' AND id_receveur_message = '"+userid2+"' OR id_emetteur_message='"+userid2+"' AND id_receveur_message = '"+userid+"' ORDER BY date_message ASC ;" );
        ui->listMessage->clear();
        while(query.next())
        {
           // QListWidgetItem *item = query.value(1);

            ui->listMessage->addItem(query.value(2).toString()+" >> "+query.value(1).toString()+"   "+query.value(4).toString());

        }
    }

}

//envoi de message
void message_fen::on_envoi_message_button_clicked()
{
    QString message_envoi =  ui->messageLineEdit->text() ;

    Users current;
    QString currentDate = current.currentDateTime();
    userid = ui->id_label->text();
    QSqlQuery query;
    //query.exec("INSERT INTO messages(message_texte,id_emetteur_message,id_receveur_message,date_message) VALUES('"+message_envoi+"','"+userid+"','"+userid2+"','"+currentDate+"');" );
    query.prepare("INSERT INTO messages(message_texte,id_emetteur_message,id_receveur_message,date_message) VALUES( :message_envoi, :userid,:userid2, :currentDate);" );
    query.bindValue(":message_envoi", message_envoi);
    query.bindValue(":userid", userid);
    query.bindValue(":userid2", userid2);
    query.bindValue(":currentDate", currentDate);
    query.exec();
//    if(!query.next())
//    {
//        QMessageBox::critical(0, QObject::tr("Erreur de connexion"),query.lastError().text());

//    }
     ui->messageLineEdit->clear();
}


//clique sur la liste d'amis pour afficher un la discussion
void message_fen::on_liste_amis_clicked()
{
    userid = ui->id_label->text();
    userid2 = ui->liste_amis->currentItem()->text();
    QSqlQuery query;
    query.exec(" SELECT * FROM messages WHERE id_emetteur_message='"+userid+"' AND id_receveur_message = '"+userid2+"' OR id_emetteur_message='"+userid2+"' AND id_receveur_message = '"+userid+"' ORDER BY date_message ASC ;" );
    ui->listMessage->clear();
    while(query.next())
    {
       // QListWidgetItem *item = query.value(1);

        ui->listMessage->addItem(query.value(2).toString()+" >> "+query.value(1).toString()+"   "+query.value(4).toString());

    }
}

//envoi d'invitation
void message_fen::on_pushButton_clicked()
{
    userid = ui->id_label->text();

    QString user_receveur = ui->id_line->text();

    QString id_line = ui->id_line->text();

    if(id_line.isEmpty())
    {
         QMessageBox::information(0,"Invitation", "Le champs est vide");
    }
    else
    {
         QSqlQuery query;

         query.exec("SELECT user_id FROM users WHERE user_id = '"+user_receveur+"';");
         if(query.next())
         {
             query.exec("INSERT INTO invitations (id_emetteur_invitation, id_receveur_invitation) VALUES ('"+userid+"','"+user_receveur+"');");

              QMessageBox::information(0,"Invitation", "Votre invitation a été bien envoyée");

              ui->id_line->clear();
         }
         else
         {
               QMessageBox::information(0,"Invitation", "L' identifiant "+user_receveur+ " n'existe pas");
         }


    }

}

void message_fen::on_liste_invitation_clicked()
{
    QMessageBox msgBox;
    msgBox.setInformativeText("Voulez vous accepter cette invitation.");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    userid = ui->id_label->text();
    userid2 = ui->liste_invitation->currentItem()->text();

     if (ret == QMessageBox::Yes)
     {



         QSqlQuery query;
         query.exec("INSERT INTO amis (user_id1, user_id2) VALUES ('"+userid+"','"+userid2+"');");
         query.exec("INSERT INTO amis (user_id1, user_id2) VALUES ('"+userid2+"','"+userid+"');");

          QMessageBox::information(0,"Invitation", " Invitation Acceptée ");

          query.exec("UPDATE invitations SET invitation_statut = 1 WHERE id_emetteur_invitation ='"+userid2+"' AND id_receveur_invitation = '"+userid+"';");


     }
     else if(ret == QMessageBox::No)
     {
         //query.exec("SELECT id_emetteur_invitation FROM invitations WHERE invitation_statut = 0 AND  id_receveur_invitation = '"+userid+"'; " );
         QSqlQuery query;
         query.exec("DELETE FROM invitations WHERE id_emetteur_invitation ='"+userid2+"' AND id_receveur_invitation = '"+userid+"';");


           QMessageBox::information(0,"Invitation", "Invitation supprimée");




     }



}



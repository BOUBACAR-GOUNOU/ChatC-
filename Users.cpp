#include "Users.h"
#include "QString"
#include "inscription_fen.h"
#include "QSqlQuery"
#include "QMessageBox"
#include "ctime"
#include "QSqlError"
#include "bd_connexion.h"
#include "QListWidget"

//Users::Users():user_id(""){

//}

QString Users::getUser_id() {
    return user_id;
}

void Users::setUser_id(QString user_id) {
	this->user_id = user_id;

}

void Users::getUser_pseudo() {
	// TODO - implement Users::getUser_pseudo
	throw "Not yet implemented";
}

void Users::setUser_pseudo(int user_pseudo) {
	this->user_pseudo = user_pseudo;
}

//fonction d'affichage de date
QString Users::currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%X %d/%m/%Y", &tstruct);

    return buf;
}

//inscription
bool Users::inscrire(QString m_id, QString m_pseudo, QString m_pass) {

   QSqlQuery requete;
   requete.exec("SELECT user_id FROM users WHERE user_id = '"+m_id+"';");

   if(requete.next())
   {
            QMessageBox::information(0,"information","L'identifiant existe");

            return false;
   }
   else
   {
     if(m_id.isEmpty() || m_pseudo.isDetached()|| m_pass.isEmpty())
     {
         QMessageBox::critical(0,"Inscription","Veuillez remplir tous les champs");

         return false;
     }
     else
     {
         requete.prepare("INSERT INTO users(user_id, user_pseudo, user_pass, date_inscription) VALUES (:m_id, :m_pseudo, :m_pass, :currentdate);");
         requete.bindValue(":m_id", m_id);
         requete.bindValue(":m_pseudo", m_pseudo);
         requete.bindValue(":m_pass", m_pass);
         requete.bindValue(":currentdate", currentDateTime() );

         bool req =  requete.exec();
         if(req)
         {
             QMessageBox::information(0,"Inscription","Inscription réussie");

         }
     }
   }

   return true;

}

//connexion
bool Users::connecter( QString m_id, QString m_pass) {
    QSqlQuery requete;

    requete.exec("SELECT * FROM users WHERE user_id = '"+m_id+"' AND user_pass = '"+m_pass+"'; " );

    if(!requete.next())
    {
         QMessageBox::information(0,"information","connexion non reussi, identifiant ou mot de pass erroné");
          return false;
    }

          return true;

}



void Users::deconnecter() {
    // TODO - implement Users::deconnecter
    throw "Not yet implemented";
}

void Users::afficherUser() {
	// TODO - implement Users::afficherUser
	throw "Not yet implemented";
}

void Users::modifierUser() {
	// TODO - implement Users::modifierUser
	throw "Not yet implemented";
}

void Users::supprimerUser() {
	// TODO - implement Users::supprimerUser
	throw "Not yet implemented";
}

void Users::getDate_inscription() {
	// TODO - implement Users::getDate_inscription
	throw "Not yet implemented";
}

void Users::setDate_inscription(int date_inscription) {
	this->date_inscription = date_inscription;
}

void Users::getUser_pass() {
	// TODO - implement Users::getUser_pass
	throw "Not yet implemented";
}

void Users::setUser_pass(int user_pass) {
	this->user_pass = user_pass;
}


//QString Users::afficherListe_amis(QString userid )
//{
//    QSqlQuery query;
//    query.exec("SELECT user_id2 FROM amis WHERE user_id1 = '"+userid+"'; " );
//        while(query.next())
//         {
//                return query.value(0).toString();

//         }
//}

//QString Users::afficherListe_invitation(QString)
//{
//    QSqlQuery query;
//    query.exec("SELECT id_emetteur_invitation FROM invitations WHERE invitation_statut = 0 AND  id_receveur_invitation = '"+userid+"'; " );
//    while(query.next())
//     {
//             ui->liste_invitation->addItem(query.value(0).toString());
//     }
//}

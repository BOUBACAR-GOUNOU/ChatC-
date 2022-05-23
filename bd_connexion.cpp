#include "bd_connexion.h"
#include "QMessageBox"
#include "qstring.h"
#include "QSqlDatabase"
#include "qsqlerror.h"




bd_connexion::bd_connexion()
{

}


bool bd_connexion::getConnexion()
{
    bd = QSqlDatabase::addDatabase("QSQLITE");
    bd.setHostName("localhost");
    bd.setDatabaseName("message.db");
    bd.setUserName("root");
    bd.setPassword("");

    if (!bd.open())
    {
        QMessageBox::critical(0, QObject::tr("Erreur de connexion"),"Veuillez créer la BDD message");

        return false;
    }
   /* else
    {
        QMessageBox::information(0,"","Connexion reussi");
    }*/

    return true;

}

void bd_connexion::createTable()
{
    // table users
      query.exec(
                "CREATE TABLE IF NOT EXISTS `users` "
                "(`user_id` VARCHAR (255) NOT NULL,"
                " `user_pseudo` VARCHAR (255) NOT NULL,"
                "`user_pass` VARCHAR (255) NOT NULL,"
                "`date_inscription` DATETIME NOT NULL,"
                "PRIMARY KEY ( `user_id`) );"
                );

    //table amis
      query.exec("CREATE TABLE IF NOT EXISTS amis "
                 "(user_id1 VARCHAR (255) NOT NULL,"
                 "user_id2 VARCHAR (255) NOT NULL,"
                 "PRIMARY KEY (user_id1,user_id2),"
                 "FOREIGN KEY (user_id1)REFERENCES Users (user_id),"
                 "FOREIGN KEY (user_id2)"
                 "REFERENCES Users (user_id) );");

    //table messages
      query.exec("CREATE TABLE IF NOT EXISTS messages "
                 "(message_id VARCHAR(255) NULL,"
                 "message_texte TEXT, "
                 "id_emetteur_message VARCHAR (255) NOT NULL,"
                 "id_receveur_message VARCHAR (255) NOT NULL,"
                 "date_message DATETIME NOT NULL, "
                 "PRIMARY KEY (message_id),"
                 "FOREIGN KEY (id_emetteur_message,id_receveur_message)"
                 "REFERENCES amis (user_id1, user_id2));");

      //table invitation
      query.exec("CREATE TABLE IF NOT EXISTS invitations"
                 "(invitation_id INTEGER NOT NULL,"
                 "id_emetteur_invitation VARCHAR (255) NOT NULL,"
                 "id_receveur_invitation  VARCHAR (255) NOT NULL,"
                 "invitation_statut INTEGER DEFAULT(0)  NOT NULL,"
                 "date_invitation DATETIME,"
                 "PRIMARY KEY (invitation_id AUTOINCREMENT),"
                 "FOREIGN KEY (id_emetteur_invitation)"
                 "REFERENCES Users (user_id),"
                 "FOREIGN KEY (id_receveur_invitation)"
                 "REFERENCES Users (user_id) );");

}

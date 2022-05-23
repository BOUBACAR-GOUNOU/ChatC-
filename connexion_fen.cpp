#include "connexion_fen.h"
#include "ui_connexion_fen.h"
#include "inscription_fen.h"
#include "message_fen.h"
#include "bd_connexion.h"
#include "Users.h"
#include "QString"
#include "message_fen.h"

connexion_fen::connexion_fen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::connexion_fen)
{
    bd_connexion v ;
    ui->setupUi(this);
    v.createTable() ;//creation des tables
}

connexion_fen::~connexion_fen()
{
    delete ui;
}


QString idenfiant;
void connexion_fen::on_pushButton_2_clicked()
{
    QString idenfiant = ui->id_connexion_line->text().toUtf8();
    QString password = ui->pass_connexion_line->text().toUtf8();

   Users users;
   bool result = users.connecter(idenfiant,password);

   if(result)
   {
//       message_fen *f = new message_fen();
//       f->show();
//       this->close();

        message_fen *f = new message_fen();
        f->setVar(idenfiant);
        f->show();
        this->close();

   }
}

//inscription
void connexion_fen::on_inscription_button_clicked()
{
    inscription_fen *f = new inscription_fen();
    f->show();
    this->close();
}

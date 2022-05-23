#include "inscription_fen.h"
#include "ui_inscription_fen.h"
#include "connexion_fen.h"
#include "Users.h"

inscription_fen::inscription_fen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::inscription_fen)
{
    ui->setupUi(this);
}

inscription_fen::~inscription_fen()
{
    delete ui;
}

void inscription_fen::on_pushButton_2_clicked()
{
    QString idenfiant = ui->identifiant_line->text().toUtf8();
    QString pseudo = ui->pseudo_line->text().toUtf8();
    QString password = ui->pass_line->text().toUtf8();

   Users users;
   bool inscri = users.inscrire(idenfiant,pseudo,password);
   if(inscri)
   {
       ui->identifiant_line->clear();
       ui->pseudo_line->clear();
       ui->pass_line->clear();
   }
}

void inscription_fen::on_retour_ins_button_clicked()
{
    connexion_fen *f = new connexion_fen();
    f->show();
    this->close();
}

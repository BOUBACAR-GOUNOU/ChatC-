#ifndef MESSAGE_FEN_H
#define MESSAGE_FEN_H

#include <QDialog>

namespace Ui {
class message_fen;
}

class message_fen : public QDialog
{
    Q_OBJECT

public:
    explicit message_fen(QWidget *parent = 0);
    ~message_fen();
     void setVar(QString acc);

private slots:
     void on_pushButton_2_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_pushButton_3_clicked();

     void on_envoi_message_button_clicked();

     void on_liste_amis_clicked();

     void on_pushButton_clicked();

     void on_liste_invitation_clicked();

private:
    Ui::message_fen *ui;
};

#endif // MESSAGE_FEN_H

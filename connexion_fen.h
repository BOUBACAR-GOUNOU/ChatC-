#ifndef CONNEXION_FEN_H
#define CONNEXION_FEN_H

#include <QMainWindow>

namespace Ui {
class connexion_fen;
}

class connexion_fen : public QMainWindow
{
    Q_OBJECT

public:
    explicit connexion_fen(QWidget *parent = 0);
    ~connexion_fen();

private slots:
    void on_pushButton_2_clicked();

    void on_inscription_button_clicked();

private:
    Ui::connexion_fen *ui;
};

#endif // CONNEXION_FEN_H

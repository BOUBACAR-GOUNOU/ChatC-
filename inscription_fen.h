#ifndef INSCRIPTION_FEN_H
#define INSCRIPTION_FEN_H

#include <QDialog>

namespace Ui {
class inscription_fen;
}

class inscription_fen : public QDialog
{
    Q_OBJECT

public:
    explicit inscription_fen(QWidget *parent = 0);
    ~inscription_fen();

private slots:
    void on_pushButton_2_clicked();

    void on_retour_ins_button_clicked();

private:
    Ui::inscription_fen *ui;
};

#endif // INSCRIPTION_FEN_H

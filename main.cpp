#include "connexion_fen.h"
#include "bd_connexion.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bd_connexion v ;
    v.getConnexion(); //connexion à la base de données

    connexion_fen w;
    w.show();

    return a.exec();
}

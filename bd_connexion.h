#ifndef BD_CONNEXION_H
#define BD_CONNEXION_H
#include <QSqlDatabase>
#include "QSqlQuery"
class bd_connexion
{
public:
    bd_connexion();
    bool getConnexion();
    void createTable();
    QSqlDatabase bd;

private:

   QSqlQuery query;


};

#endif // BD_CONNEXION_H

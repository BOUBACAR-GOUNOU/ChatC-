#ifndef USERS_H
#define USERS_H
#include <QString>
#include "vector"
#include "QListWidget"

class Users {

private:
    QString user_id;
	int user_pseudo;
	int date_inscription;
	int user_pass;

public:
    QString getUser_id();

    void setUser_id(QString user_id);

	void getUser_pseudo();

	void setUser_pseudo(int user_pseudo);

    bool inscrire(QString m_id, QString m_pseudo, QString m_pass);

    bool connecter(QString m_id, QString m_pass);

	void deconnecter();

	void afficherUser();

	void modifierUser();

	void supprimerUser();

	void getDate_inscription();

	void setDate_inscription(int date_inscription);

	void getUser_pass();

	void setUser_pass(int user_pass);

    QString currentDateTime();

    QString afficherListe_amis(QString userid);

    QString afficherListe_invitation(QString userid);




};

#endif

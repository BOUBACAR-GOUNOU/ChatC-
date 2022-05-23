#ifndef MESSAGES_H
#define MESSAGES_H

class Messages {

private:
	int message_id;
	int message_texte;
	int date_message;

public:
	void getMessage_id();

	void setMessage_id(int message_id);

	void getMessage_texte();

	void setMessage_texte(int message_texte);

	void envoyerMessage();

	void recevoirMessage();

	void afficherMessage();

	void supprimerMessage();

	void getDate_message();

	void setDate_message(int date_message);
};

#endif

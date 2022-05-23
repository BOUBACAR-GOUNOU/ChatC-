#ifndef INVITATIONS_H
#define INVITATIONS_H

class Invitations {

private:
	int invitation_id;
	int invitation_statut;
	int date_invitation;

public:
	void getInvitation_id();

	void setInvitation_id(int invitation_id);

	void getInvitation_statut();

	void setInvitation_statut(int invitation_statut);

	void envoyerInvitation();

	void getDate_invitation();

	void setDate_invitation(int date_invitation);
};

#endif

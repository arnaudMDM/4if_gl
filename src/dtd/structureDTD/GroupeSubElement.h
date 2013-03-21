#ifndef GROUPESUBELEMENT_H_
#define GROUPESUBELEMENT_H_

using namespace std;

enum Quantificateur{
	INTERROGATION,
	CROIX,
	ETOILE,
	AUCUN
};

class GroupeSubElement{
protected:
	Quantificateur quantificateur;

public:
	virtual void Afficher()=0; 
}

#endif
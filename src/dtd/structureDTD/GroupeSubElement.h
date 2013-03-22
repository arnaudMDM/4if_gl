#ifndef GROUPESUBELEMENT_H_
#define GROUPESUBELEMENT_H_

using namespace std;

#include <string>

enum Quantificateur
{
	INTERROGATION,
	CROIX,
	ETOILE,
	AUCUN
};

class GroupeSubElement
{
protected:
	Quantificateur quantificateur;

public:
	virtual void Afficher() const =0;
	virtual string getRegEx() const =0;
};

#endif
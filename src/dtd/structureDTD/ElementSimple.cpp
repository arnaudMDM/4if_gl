#include "ElementSimple.h"
#include <iostream>

ElementSimple::ElementSimple(string n, Quantificateur q)
{
	nom = n;
	quantificateur = q;
}

ElementSimple::~ElementSimple() {}

void ElementSimple::Afficher() const
{
	cout << nom;
	switch (quantificateur)
	{
		case INTERROGATION :
			cout << "?";
			break;
		case CROIX :
			cout << "+";
			break;
		case ETOILE :
			cout << "*";
			break;
		default :
	}
}

string ElementSimple::getRegEx() const
{
	string retour = nom;
	switch (quantificateur)
	{
		case INTERROGATION :
			retour += "?";
			break;
		case CROIX :
			retour += "+";
			break;
		case ETOILE :
			retour += "*";
			break;
		default :
	}
}
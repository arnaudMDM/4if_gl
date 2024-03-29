#include "ElementSequence.h"
#include <iostream>

using namespace std; 

ElementSequence::ElementSequence(list<GroupeSubElement*> * l,Quantificateur q)
{
	listGroupeSubElement = l;
	quantificateur = q;
}

ElementSequence::~ElementSequence()
{
	if(listGroupeSubElement!=NULL)
	{
		list<GroupeSubElement*>::iterator it;
		for (it = this->listGroupeSubElement->begin(); it != this->listGroupeSubElement->end(); it++)
		{
			if((*it)!=NULL)
				delete(*it);
		}

		delete(this->listGroupeSubElement);
	}
}

void ElementSequence::Afficher() const
{
	cout << "(";
	list<GroupeSubElement*>::iterator it = listGroupeSubElement->begin();

	(*it)->Afficher();

	for (it++; it != listGroupeSubElement->end(); it++)
	{
		cout << ",";
		(*it)->Afficher();
	}
	
	cout << ")";

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
			break;
	}
}

string ElementSequence::getRegEx() const
{
	string retour = "(";
	list<GroupeSubElement*>::iterator it;

	for (it = listGroupeSubElement->begin(); it != listGroupeSubElement->end(); it++)
	{	
		retour += (*it)->getRegEx();
	}
	
	retour += ")";

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
			break;
	}
	return retour; 
}


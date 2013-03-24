using namespace std; 

#include "ElementChoix.h"
#include <iostream>

ElementChoix::ElementChoix(list<GroupeSubElement*> * l, Quantificateur q)
{
	listGroupeSubElement = l;
	quantificateur = q;
}

ElementChoix::~ElementChoix()
{
	list<GroupeSubElement*>::iterator it;
	for (it = this->listGroupeSubElement->begin(); it != this->listGroupeSubElement->end(); it++)
	{
		delete(*it);
	}

	delete(this->listGroupeSubElement);
}

void ElementChoix::Afficher() const
{
	cout << "(";
	list<GroupeSubElement*>::iterator it = listGroupeSubElement->begin();

	(*it)->Afficher();

	for (it++; it != listGroupeSubElement->end(); it++)
	{
		cout << "|";
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
		default : break;  
	}
}

string ElementChoix::getRegEx() const
{
	string retour = "(";
	list<GroupeSubElement*>::iterator it = listGroupeSubElement->begin();

	retour += (*it)->getRegEx();

	for (it++; it != listGroupeSubElement->end(); it++)
	{
		retour += "|";
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

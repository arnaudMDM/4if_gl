/*
 * ElementDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

using namespace std; 

#include "ElementDTD.h"
#include <iostream>


ElementDTD::ElementDTD()
{
	/* bloc vide */
}

ElementDTD::~ElementDTD()
{
	delete(groupeSubElement);

	set<AttributDTD*>::iterator it2;
	for (it2 = this->setAttributDTD->begin(); it2 != this->setAttributDTD->end(); it2++)
	{
		delete(*it2);
	}

	delete(this->setAttributDTD);
}

ElementDTD::ElementDTD(GroupeSubElement* groupeSubElement)
{
	this->setAttributDTD = new set<AttributDTD*>();
	this->groupeSubElement=groupeSubElement;
}

void ElementDTD::setNom(string nom)
{
	this->nom = nom;
}

/*list<ElementDTD*> * ElementDTD::getLstElementDTD() const
{
    return lstElementDTD;
}*/

set<AttributDTD*> * ElementDTD::getSetAttributDTD() const
{
    return setAttributDTD;
}

string ElementDTD::getNom() const
{
    return nom;
}

void ElementDTD::ajouterAttribut(set<AttributDTD *> * setAtt)
{
	setAttributDTD->insert(setAtt->begin(),setAtt->end());
}

void ElementDTD::Afficher() const
{
	cout<< "<!ELEMENT " << nom << " ";
	groupeSubElement->Afficher();
	cout<< ">" << endl; 

	set<AttributDTD*>::iterator it;
	for (it = setAttributDTD->begin(); it != setAttributDTD->end(); it++)
	{
		(*it)->Afficher(nom);
	}

}

string ElementDTD::getRegEx()
{
	string regEx = "^";
	regEx += groupeSubElement->getRegEx();
	regEx += "$";

	return regEx;
}

GroupeSubElement * ElementDTD::getGroupeSubElement()
{
	return groupeSubElement;  
}

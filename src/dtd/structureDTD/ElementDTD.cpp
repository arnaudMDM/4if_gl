/*
 * ElementDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementDTD.h"

ElementDTD::ElementDTD() {

}

ElementDTD::~ElementDTD() {

	delete(groupeSubElement);

	set<AttributDTD*>::iterator it2;
	for (it2 = this->setAttributDTD->begin(); it2 != this->setAttributDTD->end(); it2++)
	{
		delete(*it2);
	}

	delete(this->setAttributDTD);
}

ElementDTD::ElementDTD(bool isText,GroupeSubElement* groupeSubElement)
{
	this->isText = isText;
	this->setAttributDTD = new set<AttributDTD*>();
	this->groupeSubElement=groupeSubElement;
}

void ElementDTD::setNom(string nom)
{
	this->nom = nom;
}

bool ElementDTD::getIsText() const
{
    return isText;
}

/*list<ElementDTD*> * ElementDTD::getLstElementDTD() const
{
    return lstElementDTD;
}*/

/*set<AttributDTD*> * ElementDTD::getSetAttributDTD() const
{
    return setAttributDTD;
}*/

string ElementDTD::getNom() const
{
    return nom;
}

void ElementDTD::ajouterAttribut(set<AttributDTD *> * setAtt)
{

		setAttributDTD->insert(setAtt->begin(),setAtt->end());
}

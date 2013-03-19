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
	list<ElementDTD*>::iterator it;
	for (it = this->lstElementDTD->begin(); it != this->lstElementDTD->end(); it++)
	{
		delete(*it);
	}

	delete(this->lstElementDTD);

	set<AttributDTD*>::iterator it2;
	for (it2 = this->setAttributDTD->begin(); it2 != this->setAttributDTD->end(); it2++)
	{
		delete(*it2);
	}

	delete(this->setAttributDTD);
}

ElementDTD::ElementDTD(string nom, bool isText)
{
	this->nom = nom;
	this->isText = isText;
	this->lstElementDTD = new list<ElementDTD*>();
	this->setAttributDTD = new set<AttributDTD*>();
}

bool ElementDTD::getIsText() const
{
    return isText;
}

list<ElementDTD*> * ElementDTD::getLstElementDTD() const
{
    return lstElementDTD;
}

set<AttributDTD*> * ElementDTD::getSetAttributDTD() const
{
    return setAttributDTD;
}

string ElementDTD::getNom() const
{
    return nom;
}

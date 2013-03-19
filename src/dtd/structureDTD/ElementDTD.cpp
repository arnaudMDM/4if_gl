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
	delete(this->lstElementDTD);
}

ElementDTD::ElementDTD(string nom, bool isText)
{
	this->nom = nom;
	this->isText = isText;
	this->lstElementDTD = new list<ElementDTD>();
}

bool ElementDTD::getIsText() const
{
    return isText;
}

list<ElementDTD> * ElementDTD::getLstElementDTD() const
{
    return lstElementDTD;
}

string ElementDTD::getNom() const
{
    return nom;
}

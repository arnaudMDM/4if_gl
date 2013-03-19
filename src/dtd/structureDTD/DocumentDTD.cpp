/*
 * DocumentDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "DocumentDTD.h"

DocumentDTD::DocumentDTD() {
	this->mapElementDTD = new map<string, ElementDTD*>();
}

DocumentDTD::~DocumentDTD() {
	map<string, ElementDTD*>::iterator it;
	for (it = this->mapElementDTD->begin(); it != this->mapElementDTD->end(); it++)
	{
		delete(it->second);
	}
	delete(this->mapElementDTD);
}

map<string, ElementDTD*> * DocumentDTD::getElementsDTD() const
{
	return mapElementDTD;
}

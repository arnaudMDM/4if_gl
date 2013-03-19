/*
 * DocumentDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "DocumentDTD.h"

DocumentDTD::DocumentDTD(map<string, ElementDTD*> * mapElementDTD) {
	this->mapElementDTD = mapElementDTD;
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

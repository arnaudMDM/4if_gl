/*
 * DocumentDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "DocumentDTD.h"

DocumentDTD::DocumentDTD() {
	this->setElementDTD = new set<ElementDTD>();
}

DocumentDTD::~DocumentDTD() {
}

set<ElementDTD> DocumentDTD::getElementsDTD() const
{
	return *setElementDTD;
}




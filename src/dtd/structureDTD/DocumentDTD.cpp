/*
 * DocumentDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "DocumentDTD.h"

DocumentDTD::DocumentDTD() {
	this->lstElementDTD = new list<ElementDTD>();

}

DocumentDTD::~DocumentDTD() {
}

list<ElementDTD> DocumentDTD::getElementDTD() const
{
	return *lstElementDTD;
}



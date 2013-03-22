/*
 * DocumentDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

using namespace std;

#include "DocumentDTD.h"

DocumentDTD::DocumentDTD()
{
	/* bloc vide */
}

DocumentDTD::~DocumentDTD()
{
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

void DocumentDTD::setMapElementDTD(map<string, ElementDTD*> * m)
{
	this->mapElementDTD = m;
}

void DocumentDTD::Afficher()
{
	map<string, ElementDTD*>::iterator it; 
	for(it = mapElementDTD->begin(); it != mapElementDTD->end(); it++)
	{
		(it->second)->Afficher(); 
	} 

}

/*
 * DocumentDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

using namespace std;

#include <iostream>
#include "DocumentDTD.h"

DocumentDTD::DocumentDTD()
{
	mapElementDTD=NULL;
	/* bloc vide */
}

DocumentDTD::~DocumentDTD()
{
	if(mapElementDTD!=NULL)
	{
		map<string, ElementDTD*>::iterator it;
		for (it = this->mapElementDTD->begin(); it != this->mapElementDTD->end(); it++)
		{
			if((it->second)!=NULL)
				delete(it->second);
		}
		delete(this->mapElementDTD);
	}
}

map<string, ElementDTD*> * DocumentDTD::getElementsDTD() const
{
	return mapElementDTD;
}

void DocumentDTD::setMapElementDTD(map<string, ElementDTD*> * m)
{
	this->mapElementDTD = m;
	//VerificationCoherence(); 
}

void DocumentDTD::Afficher()
{
	map<string, ElementDTD*>::iterator it; 
	for(it = mapElementDTD->begin(); it != mapElementDTD->end(); it++)
	{
		(it->second)->Afficher(); 
	} 
}

// TODO 
/* bool DocumentDTD::VerificationCoherence()
{
	/*map<string, ElementDTD*>::iterator it; 
	for (it = mapElementDTDbegin() ; it != mapElementDTD.end() ; it++)
	{
		ElementDTD * tmpElement = it->second;
		GroupeSubElement tmpElementFils =  
	}
	return true; 
}*/ 

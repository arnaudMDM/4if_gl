/*
 * Document.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "Document.h"
#include <iostream>

Document::Document() {
	elementBalise = NULL;
}

Document::~Document() {
    if(elementBalise!=NULL)
        delete(elementBalise);
	// TODO Auto-generated destructor stub
}

/*Document::Document(string version, string encoding, ElementBalise elementBalise) : version(version), encoding(encoding), elementBalise(elementBalise){

}*/


void Document::afficher()
{
	cout << "<!DOCTYPE " << this->nomXml << " SYSTEM \"" <<this->nomDtd<< "\">" << endl;
    elementBalise->afficher();
}

void Document::setElementBalise(ElementBalise * elementBalise)
{
    this->elementBalise = elementBalise;
}

void Document::setNomDtd(string nomDtd)
{
    this->nomDtd = nomDtd;
}

/*void Document::setNomFeuilleDeStyle(list<string> nomFeuilleDeStyle)
ElementBalise * Document::getElementBalise()
{
   return &elementBalise;
}

void Document::setNomFeuilleDeStyle(list<string> nomFeuilleDeStyle)
{
    this->nomFeuilleDeStyle = nomFeuilleDeStyle;
}*/

string Document::getNomDtd()
{
	return this->nomDtd;
}

void Document::setNomXml(string nomXml)
{
    this->nomXml = nomXml;
}

ElementBalise * Document::getElementBalise()
{
	return this->elementBalise; 
}


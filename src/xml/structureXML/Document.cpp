/*
 * Document.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "Document.h"

Document::Document() {
	// TODO Auto-generated constructor stub

}

Document::~Document() {
	// TODO Auto-generated destructor stub
}

/*Document::Document(string version, string encoding, ElementBalise elementBalise) : version(version), encoding(encoding), elementBalise(elementBalise){

}*/


void Document::afficher()
{
    elementBalise.afficher();
}

void Document::setElementBalise(ElementBalise elementBalise)
{
    this->elementBalise = elementBalise;
}

void Document::setNomDtd(string nomDtd)
{
    this->nomDtd = nomDtd;
}
<<<<<<< .mine

ElementBalise * Document::getElementBalise()
{
   return &elementBalise;
}
=======

void Document::setNomFeuilleDeStyle(list<string> nomFeuilleDeStyle)
{
    this->nomFeuilleDeStyle = nomFeuilleDeStyle;
}

void Document::setNomXml(string nomXml)
{
    this->nomXml = nomXml;
}

>>>>>>> .r35

/*
 * Document.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "DocumentXSL.h"
#include <iostream>

DocumentXSL::DocumentXSL() 
{
	// elementXSL = NULL;
}

DocumentXSL::~DocumentXSL() 
{
	// TODO Auto-generated destructor stub
}


void DocumentXSL::afficher()
{
	cout << "<?xml version=\"1.0\"?>" << endl;
   	elementXSL->afficher();
}

void DocumentXSL::setElementXSL(ElementXSL * elementXSL)
{
    this->elementXSL = elementXSL;
}


string DocumentXSL::getVersion()
{
	return this->version;
}

void DocumentXSL::setVersion(string version)
{
	this->version = version; 
}

string DocumentXSL::getStylesheet()
{
	return this->stylesheet;
}


ElementXSL * DocumentXSL::getElementXSL()
{
	return this->elementXSL; 
}


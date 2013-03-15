/*
 * ElementBalise.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementBalise.h"

ElementBalise::ElementBalise() {
}

ElementBalise::~ElementBalise() {
}

ElementBalise::ElementBalise(string nom)
{
	this->nom = nom;
	this->lstAbstractElement = new list<AbstractElement>();
}

string ElementBalise::getNom() const
{
    return nom;
}

list<AbstractElement> ElementBalise::getLstAbstractElement() const
{
    return *lstAbstractElement;
}

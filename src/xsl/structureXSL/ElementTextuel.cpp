/*
 * ElementTextuel.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementTextuel.h"
#include <iostream>

ElementTextuel::ElementTextuel(string Texte) 
{
	this->Texte = Texte; 
	type = TEXTE;
}

ElementTextuel::~ElementTextuel() {}

void ElementTextuel::afficher()
{
	cout << Texte;
}

string ElementTextuel::getTexte() const
{
    return Texte;
}

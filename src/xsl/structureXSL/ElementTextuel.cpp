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

}

ElementTextuel::~ElementTextuel() {}

void ElementTextuel::afficher()
{

}

string ElementTextuel::getTexte() const
{
    return Texte;
}

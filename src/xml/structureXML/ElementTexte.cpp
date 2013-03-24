/*
 * ElementTexte.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementTexte.h"
#include <iostream>

ElementTexte::ElementTexte(string Texte) {
	this->Texte = Texte; 
	isText=true;
}

ElementTexte::~ElementTexte() {
}

void ElementTexte::afficher()
{
   cout<<Texte<<endl;
}

string ElementTexte::getTexte() const
{
    return Texte;
}

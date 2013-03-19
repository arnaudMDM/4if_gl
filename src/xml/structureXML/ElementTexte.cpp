/*
 * ElementTexte.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementTexte.h"

ElementTexte::ElementTexte() {

}

ElementTexte::ElementTexte(const ElementTexte&eT)
{
	Texte=Et;
}

ElementTexte::ElementTexte(string s)
{
	Texte=s;
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

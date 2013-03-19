/*
 * AttributXML.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "AttributXML.h"
#include <iostream>

AttributXML::AttributXML() {
	
}

AttributXML::~AttributXML() {
	
}

AttributXML::AttributXML(string nom, string valeur) : nom(nom), valeur(valeur)
{}

void AttributXML::afficher()
{
    cout << " " << nom << "=\"" << valeur << "\"";
}

string AttributXML::getNom() const
{
    return nom;
}

string AttributXML::getValeur() const
{
    return valeur;
}

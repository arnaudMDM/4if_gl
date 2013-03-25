/*
 * AttributXSL.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "AttributXSL.h"
#include <iostream>

AttributXSL::AttributXSL() {}
AttributXSL::~AttributXSL() {}

AttributXSL::AttributXSL(string nom, string valeur) : nom(nom), valeur(valeur)
{}

void AttributXSL::afficher() const
{
	cout << nom << "=\"" << valeur << "\"";
}

string AttributXSL::getNom() const
{
    return nom;
}

string AttributXSL::getValeur() const
{
    return valeur;
}

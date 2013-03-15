/*
 * AttributXML.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "AttributXML.h"

AttributXML::AttributXML() {
	// TODO Auto-generated constructor stub

}

AttributXML::~AttributXML() {
	// TODO Auto-generated destructor stub
}

AttributXML::AttributXML(string nom, string valeur) : nom(nom), valeur(valeur)
{}

string AttributXML::getNom() const
{
    return nom;
}

string AttributXML::getValeur() const
{
    return valeur;
}

/*
 * AttributDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "AttributDTD.h"

AttributDTD::AttributDTD() {
}

AttributDTD::~AttributDTD() {
}

AttributDTD::AttributDTD(string nom, string valeur):nom(nom),valeur(valeur)
{}

string AttributDTD::getNom() const
{
    return nom;
}

string AttributDTD::getValeur() const
{
    return valeur;
}

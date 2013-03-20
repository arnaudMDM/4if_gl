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

AttributDTD::AttributDTD(string nomAttribut, string valeur,string nomElement):nomAttribut(nomAttribut),valeur(valeur),nomElement(nomElement)
{}

string AttributDTD::getNom() const
{
    return nom;
}

string AttributDTD::getValeur() const
{
    return valeur;
}

/*
 * AttributDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "AttributDTD.h"
#include <iostream>

AttributDTD::AttributDTD() {
}

AttributDTD::~AttributDTD() {
}

AttributDTD::AttributDTD(string nom, string type,string defaut):nom(nom),type(type),defaut(defaut),bEnum(false)
{}

AttributDTD::AttributDTD(string nom, list<string> * listType,string defaut):nom(nom),defaut(defaut),bEnum(true)
{
	this->listType=listType;
}

string AttributDTD::getNom() const
{
    return nom;
}
/*
 * AttributDTD.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

using namespace std;

#include "AttributDTD.h"
#include <iostream>


AttributDTD::AttributDTD()
{
	/* bloc vide */
}

AttributDTD::~AttributDTD()
{
	/* bloc vide */
}

AttributDTD::AttributDTD(string nom, string type,string defaut) : nom(nom), type(type), defaut(defaut), bEnum(false)
{
	/* bloc vide */
}

AttributDTD::AttributDTD(string nom, list<string> * listType, string defaut) : nom(nom), defaut(defaut), bEnum(true)
{
	this->listType = listType;
}

string AttributDTD::getNom() const
{
    return nom;
}

void AttributDTD::Afficher(string nomElt)
{
	cout << "<!ATTLIST " << nomElt << " " << nom << " ";
	if (bEnum)
	{
		cout << "(";
		list<string>::iterator it = listType->begin();
		cout << (*it);
		for (it++; it != listType->end(); it++)
		{
			cout << "," << (*it);
		}
		cout << ")";
	}
	else
	{
		cout << type;
	}

	cout << " " << defaut << ">" << endl;;
}

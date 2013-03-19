/*
 * ElementBalise.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementBalise.h"

ElementBalise::ElementBalise() {
}

ElementBalise::~ElementBalise() {
}

ElementBalise::ElementBalise(string nom)
{
	this->nom = nom;
	this->lstAbstractElement = new list<AbstractElement*>();
}

void ElementBalise::afficher()
{
  cout << "<" << nom;
  list<AttributXML>::iterator it;
  for (it = lstAttributs->begin(); it != lstAttributs->end(); it++)
  {
  	it->afficher();
  }
  if (lstAbstractElement->size() > 0)
  {
  	cout << ">" << endl;
  	list<AbstractElement*>::iterator it2;
	for (it2 = lstAbstractElement->begin(); it2 != lstAbstractElement->end(); it2++)
  	{
   		(*it2)->afficher();
  	}
	  cout << "</" << nom << ">" << endl;
  }
  else
  {
	  cout << "/>" << endl;
  }
}

string ElementBalise::getNom() const
{
  return nom;
}

list<AbstractElement*> * ElementBalise::getLstAbstractElement() const
{
    return lstAbstractElement;
}

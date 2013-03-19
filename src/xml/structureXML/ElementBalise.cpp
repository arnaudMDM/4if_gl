/*
 * ElementBalise.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementBalise.h"

#include <iostream>

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
  set<AttributXML>::iterator it;
  for (it = setAttributs->begin(); it != setAttributs->end(); it++)
  {
  	//it->afficher();
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

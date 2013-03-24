/*
 * ElementBalise.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementBalise.h"

#include <set>
#include <iostream>

ElementBalise::ElementBalise() {
}

ElementBalise::~ElementBalise() {
  if(setAttributs!=NULL)
  {
    set<AttributXML*>::iterator it;
    for (it = setAttributs->begin(); it != setAttributs->end(); it++)
    {
      delete(*it);
    }
    delete(setAttributs);
  }
  if(lstAbstractElement!=NULL)
  {
    list<AbstractElement*>::iterator it;
    for (it = lstAbstractElement->begin(); it != lstAbstractElement->end(); it++)
    {
      delete(*it);
    }
    delete(lstAbstractElement);
  }
}

ElementBalise::ElementBalise(string nom, list<AbstractElement*> * l, set<AttributXML*> * s)
{
	this->nom = nom;
	this->lstAbstractElement = l;
	this->setAttributs = s;
  this->setAttributs = new set<AttributXML*>();
  isText=false;
}

void ElementBalise::afficher()
{
  cout << "<" << nom;
  set<AttributXML*>::iterator it;
  for (it = setAttributs->begin(); it != setAttributs->end(); it++)
  {
  	(*it)->afficher();
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

set<AttributXML*> * ElementBalise::getSetAttribut() const
{
  return setAttributs;
}

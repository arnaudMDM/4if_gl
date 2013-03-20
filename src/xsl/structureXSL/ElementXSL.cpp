/*
 * ElementXSL.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementXSL.h"

#include <set>
#include <iostream>

ElementXSL::ElementXSL() {}
ElementXSL::~ElementXSL() {}

ElementXSL::ElementXSL(string nom, list<AbstractElementXSL*> * l, set<AttributXSL*> * s)
{
	this->nom = nom;
	this->lstAbstractElementXSL = l;
	this->setAttributXSL = s;
  this->setAttributXSL = new set<AttributXSL*>();
}

void ElementXSL::afficher()
{

}

string ElementXSL::getNom() const
{
  return nom;
}

list<AbstractElementXSL*> * ElementXSL::getLstAbstractElementXSL() const
{
  return lstAbstractElementXSL;
}

set<AttributXSL*> * ElementXSL::getSetAttributXSL() const
{
  return setAttributXSL;
}

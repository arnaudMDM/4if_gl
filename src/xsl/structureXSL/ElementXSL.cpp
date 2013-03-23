/*
 * ElementXSL.cpp
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#include "ElementXSL.h"

#include <set>
#include <iostream>

using namespace std;

ElementXSL::ElementXSL() {}
ElementXSL::~ElementXSL() {}

ElementXSL::ElementXSL(Type type, list<AbstractElementXSL*> * l, AttributXSL * s)
{
	this->type = type; 
	this->lstAbstractElementXSL = l;
	this->attributXSL = s;
}

void ElementXSL::afficher()
{

}

list<AbstractElementXSL*> * ElementXSL::getLstAbstractElementXSL() const
{
  return lstAbstractElementXSL;
}

AttributXSL* ElementXSL::getAttributXSL() const
{
  return attributXSL;
}

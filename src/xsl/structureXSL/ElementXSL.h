/*
 * ElementBalise.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ELEMENTXSL_H_
#define ELEMENTXSL_H_

using namespace std;

// Includes
#include <string>
#include <list>
#include <set>
#include "AbstractElementXSL.h"
#include "AttributXSL.h"

enum Type
{
	STYLESHEET,
	TEMPLATE, 
	APPLYTEMPLATES
}; 

class ElementXSL : public AbstractElementXSL
{

// Attributs de classe
protected:
	Type type; 
	AttributXSL * attributXSL;
	list<AbstractElementXSL*> * lstAbstractElementXSL;

// Constructeurs et Méthodes
public:
	ElementXSL();
	ElementXSL(Type type, list<AbstractElementXSL*> * lstAbstractElementXSL, AttributXSL * s);
	virtual ~ElementXSL();

    Type getType() const;
    list<AbstractElementXSL*> * getLstAbstractElementXSL() const;
    AttributXSL * getAttributXSL() const;
    virtual void afficher();
};

#endif /* ELEMENTXSL_H_ */

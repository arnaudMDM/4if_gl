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

class ElementXSL : public AbstractElementXSL
{

// Attributs de classe
protected:
	AttributXSL * attributXSL;
	list<AbstractElementXSL*> * lstAbstractElementXSL;

// Constructeurs et Méthodes
public:
	ElementXSL();
	ElementXSL(string type, list<AbstractElementXSL*> * lstAbstractElementXSL, AttributXSL * s);
	virtual ~ElementXSL();

    list<AbstractElementXSL*> * getLstAbstractElementXSL() const;
    AttributXSL * getAttributXSL() const;
    virtual void afficher();
};

#endif /* ELEMENTXSL_H_ */

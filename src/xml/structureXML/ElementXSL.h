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
	string nom;
	set<AttributXSL*> * setAttributXSL;
	list<AbstractElementXSL*> * lstAbstractElementXSL;

// Constructeurs et Méthodes
public:
	ElementXSL();
	ElementXSL(string nom, list<AbstractElementXSL*> * lstAbstractElementXSL, set<AttributXSL*> * s);
	virtual ~ElementXSL();

    string getNom() const;
    list<AbstractElementXSL*> * getLstAbstractElementXSL() const;
    set<AttributXSL*> * getSetAttributXSL() const;
    virtual void afficher();
};

#endif /* ELEMENTXSL_H_ */

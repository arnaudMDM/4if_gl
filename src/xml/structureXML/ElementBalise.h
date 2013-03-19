/*
 * ElementBalise.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ELEMENTBALISE_H_
#define ELEMENTBALISE_H_

using namespace std;

// Includes
#include <string>
#include <list>
#include <set>
#include "AbstractElement.h"
#include "AttributXML.h"

class ElementBalise : public AbstractElement {

// Attributs de classe
protected:
	string nom;
	set<AttributXML*> * setAttributs;
	list<AbstractElement*> * lstAbstractElement;

// Constructeurs et Méthodes
public:
	ElementBalise();
	ElementBalise(string nom, list<AbstractElement*> * lstAbstractElement, set<AttributXML*> * s);
	virtual ~ElementBalise();
    string getNom() const;

    list<AbstractElement*> * getLstAbstractElement() const;

    set<AttributXML*> * getSetAttribut() const;

    virtual void afficher();
};

#endif /* ELEMENTBALISE_H_ */

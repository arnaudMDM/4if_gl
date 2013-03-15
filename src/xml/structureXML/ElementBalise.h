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
#include "AbstractElement.h"

class ElementBalise : public AbstractElement {

// Attributs de classe
protected:
	string nom;
	list<AbstractElement> * lstAbstractElement;

// Constructeurs et Méthodes
public:
	ElementBalise();
	ElementBalise(string nom);
	virtual ~ElementBalise();
    string getNom() const;
    list<AbstractElement> getLstAbstractElement() const;
};

#endif /* ELEMENTBALISE_H_ */

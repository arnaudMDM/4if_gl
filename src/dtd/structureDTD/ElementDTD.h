/*
 * ElementDTD.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ELEMENTDTD_H_
#define ELEMENTDTD_H_

using namespace std;

// Includes
#include <string>
#include <list>
#include <set>
#include "AttributDTD.h"

class ElementDTD {
// Attributs de classe
protected:
	string nom;
	bool isText;
	list<string> * lstElementDTD;
// Constructeurs et Méthodes
public:
	ElementDTD();
	ElementDTD(string nom, bool isText);
	virtual ~ElementDTD();
    bool getIsText() const;
    list<ElementDTD*> * getLstElementDTD() const;
    string getNom() const;
};

#endif /* ELEMENTDTD_H_ */

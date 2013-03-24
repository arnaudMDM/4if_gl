/*
 * ElementTextuel.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ELEMENTTEXTUEL_H_
#define ELEMENTTEXTUEL_H_

using namespace std;

// Includes
#include <string>
#include "AbstractElementXSL.h"

class ElementTextuel : public AbstractElementXSL  {

protected:
	string Texte;
public:
	ElementTextuel(string Texte);
	virtual ~ElementTextuel();
    virtual void afficher();
	string getTexte() const;
};

#endif /* ELEMENTTEXTUEL_H_ */

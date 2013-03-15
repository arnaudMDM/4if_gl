/*
 * ElementTexte.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ELEMENTTEXTE_H_
#define ELEMENTTEXTE_H_

using namespace std;

// Includes
#include <string>
#include "AbstractElement.h"

class ElementTexte : public AbstractElement  {

protected:
	string Texte;
public:
	ElementTexte();
	virtual ~ElementTexte();
    string getTexte() const;
};

#endif /* ELEMENTTEXTE_H_ */

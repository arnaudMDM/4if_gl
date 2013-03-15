/*
 * DocumentDTD.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef DOCUMENTDTD_H_
#define DOCUMENTDTD_H_

using namespace std;

// Includes
#include <list>
#include "ElementDTD.h"

class DocumentDTD {
// Attributs de classe
protected:
	list<ElementDTD> * lstElementDTD;
// Constructeurs et méthodes
public:
	DocumentDTD();

	virtual ~DocumentDTD();
	list<ElementDTD> getElementDTD() const;

};

#endif /* DOCUMENTDTD_H_ */

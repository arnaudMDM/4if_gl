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
#include <set>
#include "ElementDTD.h"

class DocumentDTD {
// Attributs de classe
protected:
	set<ElementDTD> * setElementDTD;
// Constructeurs et méthodes
public:
	DocumentDTD();

	virtual ~DocumentDTD();
	set<ElementDTD> getElementDTD() const;

};

#endif /* DOCUMENTDTD_H_ */

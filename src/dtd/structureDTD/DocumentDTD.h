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
#include <map>
#include <string>
#include "ElementDTD.h"

class DocumentDTD {
// Attributs de classe
protected:
	map<string, ElementDTD*> * mapElementDTD;
	map<string, ElementDTD*> * mapElementSansPere;
	map<string, ElementDTD*> * mapElementSansFils;
// Constructeurs et méthodes
public:
	DocumentDTD(map<string, ElementDTD*> * mapElementDTD);

	virtual ~DocumentDTD();
	map<string, ElementDTD*> * getElementsDTD() const;

};

#endif /* DOCUMENTDTD_H_ */

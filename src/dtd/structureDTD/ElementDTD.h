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
#include <set>
#include <map>
#include "AttributDTD.h"
#include "GroupeSubElement.h"

class ElementDTD {
// Attributs de classe
protected:
	string nom;
	bool isText;
	GroupeSubElement * groupeSubElement;
	set<AttributDTD*> * setAttributDTD;
// Constructeurs et Méthodes
public:
	ElementDTD();
	ElementDTD(bool isText,GroupeSubElement* groupeSubElement);//#PCDATA peut-on avoir #PCDATA et des fils ?
	virtual ~ElementDTD();
    bool getIsText() const;
    //list<ElementDTD*> * getLstElementDTD() const;
    //set<AttributDTD*> * getSetAttributDTD() const;
    void ajouterAttribut(set<AttributDTD *> * setAtt);
    string getNom() const;
    void setNom(string nom);
};

#endif /* ELEMENTDTD_H_ */

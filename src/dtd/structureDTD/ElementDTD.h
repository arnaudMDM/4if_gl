/*
 * ElementDTD.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ELEMENTDTD_H_
#define ELEMENTDTD_H_

// Includes
#include <string>
#include <set>
#include <map>
#include "AttributDTD.h"
#include "GroupeSubElement.h"

class ElementDTD
{
// Attributs de classe
protected:
	string nom;
	GroupeSubElement * groupeSubElement;
	set<AttributDTD*> * setAttributDTD;
// Constructeurs et Méthodes
public:
	ElementDTD();
	ElementDTD(GroupeSubElement* groupeSubElement); //#PCDATA peut-on avoir #PCDATA et des fils ?
	virtual ~ElementDTD();
    //list<ElementDTD*> * getLstElementDTD() const;
    //set<AttributDTD*> * getSetAttributDTD() const;
    void ajouterAttribut(set<AttributDTD *> * setAtt);
    string getNom() const;
    void setNom(string nom);
    void Afficher() const; 
    string getRegEx();
};

#endif /* ELEMENTDTD_H_ */
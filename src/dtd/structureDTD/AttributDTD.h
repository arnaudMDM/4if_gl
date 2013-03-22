/*
 * AttributDTD.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ATTRIBUTDTD_H_
#define ATTRIBUTDTD_H_

using namespace std;

// Includes
#include <string>
#include <list>

class AttributDTD
{
protected:
	string nom;
	string type;
	string defaut;
	list<string> * listType;
	bool bEnum;
public:
	AttributDTD();
	AttributDTD(string nom, string type,string defaut);
	AttributDTD(string nom, list<string> * listType,string defaut);
	virtual ~AttributDTD();
    string getNom() const;
    //string getValeur() const;
    void Afficher(string nomElt);
};

#endif /* ATTRIBUTDTD_H_ */

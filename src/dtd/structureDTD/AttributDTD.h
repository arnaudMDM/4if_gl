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
#include<string>

class AttributDTD {
protected:
	string nom;
	string valeur;
public:
	AttributDTD();
	AttributDTD(string nom, string valeur);
	virtual ~AttributDTD();
    string getNom() const;
    string getValeur() const;
};

#endif /* ATTRIBUTDTD_H_ */

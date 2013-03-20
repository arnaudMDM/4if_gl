/*
 * AttributXSL.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ATTRIBUTXSL_H_
#define ATTRIBUTXSL_H_

using namespace std;

// Includes
#include <string>

class AttributXSL 
{

// Attributs de classe
protected:
	string nom;
	string valeur;

// Constructeurs et classes
public:
	AttributXSL();
	AttributXSL(string nom, string valeur);
	virtual ~AttributXSL();

    string getNom() const;
    string getValeur() const;
    void afficher() const;
};

#endif /* ATTRIBUTXSL_H_ */

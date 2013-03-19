/*
 * Attribut.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ATTRIBUTXML_H_
#define ATTRIBUTXML_H_

using namespace std;

// Includes
#include <string>

class AttributXML {

// Attributs de classe
protected:
	string nom;
	string valeur;

// Constructeurs et classes
public:
	AttributXML();
	AttributXML(string nom, string valeur);
	virtual ~AttributXML();
    string getNom() const;

    string getValeur() const;
    void afficher() const;
};

#endif /* ATTRIBUTXML_H_ */

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

class DocumentDTD
{
// Attributs de classe
protected:
	map<string, ElementDTD*> * mapElementDTD;
// Constructeurs et méthodes
public:
	DocumentDTD();

	virtual ~DocumentDTD();
	map<string, ElementDTD*> * getElementsDTD() const;
	void setMapElementDTD(map<string, ElementDTD*> *);
	void Afficher();

	/** 
	 * Description : Fonction de verifier la coherence d'un fichier dtd. 
	 * Tous les fils d'element doivent être instanciés  
	 * Les erreurs seront affichées sur stderr
	 * @return : true si le document est semantiquement correct et false sinon  
	 */
	bool VerificationCoherence(); 
};

#endif /* DOCUMENTDTD_H_ */

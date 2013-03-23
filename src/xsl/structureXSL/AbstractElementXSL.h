/*
 * AbstractElementXSL.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ABSTRACTELEMENTXSL_H_
#define ABSTRACTELEMENTXSL_H_

enum Type
{
	STYLESHEET,
	TEMPLATE, 
	APPLYTEMPLATES,
	TEXTE
}; 

class AbstractElementXSL {
public:
   virtual void afficher()=0;
   Type getType()const{return type;};
protected:
	Type type;
};

#endif /* ABSTRACTELEMENTXSL_H_ */

/*
 * AbstractElement.h
 *
 *  Created on: 12 mars 2013
 *      Author: alefevre
 */

#ifndef ABSTRACTELEMENT_H_
#define ABSTRACTELEMENT_H_

class AbstractElement {
public:
   virtual void afficher()=0;
   bool getIsText()const{return isText;};
protected:
	bool isText;
};

#endif /* ABSTRACTELEMENT_H_ */

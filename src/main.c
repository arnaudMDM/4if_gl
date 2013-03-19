#include "dtd/dtd.tab.h" 
#include "xml/xml.tab.h"
#include <stdio.h>
#include <string>
#include <set>
#include <iterator>
#include <iostream>

#include "xml/structureXML/AbstractElement.h"
#include "xml/structureXML/AttributXML.h"
#include "xml/structureXML/Document.h"
#include "xml/structureXML/ElementBalise.h"
#include "xml/structureXML/ElementTexte.h"

#include "dtd/structureDTD/AttributDTD.h"
#include "dtd/structureDTD/DocumentDTD.h"
#include "dtd/structureDTD/ElementDTD.h"

int xmlparse(Document * xml);
int dtdparse();
bool verifXml(DocumentDTD * dtd, Document * xml);
bool verifNoeud(AbstractElement * noeud, map<string, ElementDTD*> * elts);

extern int xmldebug;
extern int dtddebug;
extern char * sDtd;
extern FILE * dtdin;

int main(int argc, char **argv)
{
  int err;

  Document * docXML = new Document();

  xmldebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = xmlparse(docXML);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  else  printf("Parse ended with success\n", err);

  if(docXML->getElementBalise() == NULL)
  {
    cout << "Erreur : Pas de racine définie pour le XML" << endl;
  }

  docXML->afficher();

  if (sDtd==NULL)
  {
	 printf("Aucun dtd associé\n", err);
  }

  else
  {
    dtddebug = 1;
  	FILE *file;
   	file = fopen(sDtd, "r");
	
	if(!file) {
		fprintf(stderr, "Could not open %s \n", sDtd);
		return(1);
	}
	
   	dtdin = file;
   	//dtdout = fopen("out.txt", "w");

    	err=dtdparse();
	if (err != 0) printf("Parse ended with %d error(s)\n", err);
		else  printf("Parse ended with success\n", err);
    	fclose(file);
    	//fclose(dtdout);
  }
  return 0;
}


/* ---------------------------------------- */


bool verifXml(DocumentDTD * dtd, Document * xml)
{
  if (dtd == NULL || xml == NULL)
  {
    return false;
  }

	ElementBalise * noeud;
	map<string, ElementDTD*> * elts;

	noeud = xml->getElementBalise();
	elts = dtd->getElementsDTD();
	
	return verifNoeud(noeud, elts);
}

bool verifNoeud(AbstractElement * abstractNoeud, map<string, ElementDTD*> * elts)
{

  if (abstractNoeud == NULL || elts == NULL)
  {
    return false;
  }

	ElementBalise * noeud = dynamic_cast<ElementBalise*>(abstractNoeud);

	if (noeud == 0)
	{
		// il s'agit d'un élément texte
		return true;
	}

	string nomNoeudCourant = noeud->getNom();

	ElementDTD * noeudDTD = (*elts)[nomNoeudCourant];

	// verification de l'existance du noeud courant dans la dtd
	if (noeudDTD == NULL)
	{
		return false;
	}

	// vérification des attributs du noeud courant
  set<AttributXML*> * attsXML = noeud->getSetAttribut();
  set<AttributDTD*> * attsDTD = noeudDTD->getSetAttributDTD();

  set<AttributXML*>::iterator it;
  set<AttributDTD*>::iterator it2;
  bool trouve;
  for (it = attsXML->begin(); it != attsXML->end(); it++)
  {
    trouve = false;

    for (it2 = attsDTD->begin(); it2 != attsDTD->end(); it2++)
    {
      if ((*it)->getNom() == (*it2)->getNom())
      {
        trouve = true;
        break;
      }
    }

    if (!trouve)
    {
      return false;
    }
  }

	// vérification des sous-éléments*/
  list<AbstractElement*> * lstEltsXML = noeud->getLstAbstractElement();
  list<AbstractElement*>::iterator it3;
  for (it3 = lstEltsXML->begin(); it3 != lstEltsXML->end(); it3++)
  {
    if (!verifNoeud(*(it3), elts))
    {
      return false;
    }
  }

  return true;
}

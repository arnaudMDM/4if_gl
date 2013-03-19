#include "dtd/dtd.tab.h" 
#include "xml/xml.tab.h"
#include <stdio.h>
#include <string>
#include <set>
#include <iterator>

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
bool verifNoeud(AbstractElement * noeud, map<string, ElementDTD> * elts);

extern int xmldebug;
extern int dtddebug;
extern char * sDtd;
extern FILE * dtdin;

int main(int argc, char **argv)
{
  int err;

  Document * docXML;

  xmldebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = xmlparse(docXML);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  else  printf("Parse ended with success\n", err);

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
	ElementBalise * noeud;
	map<string, ElementDTD> elts;

	noeud = xml->getElementBalise();
	elts = dtd->getElementsDTD();
	
	return verifNoeud(noeud, &elts);
}

bool verifNoeud(AbstractElement * abstractNoeud, map<string, ElementDTD> * elts)
{

	ElementBalise* noeud = dynamic_cast<ElementBalise*>(abstractNoeud);
	if (noeud == 0)
	{
		// il s'agit d'un élément texte
		return true;
	}

	string nomNoeudCourant = noeud->getNom();

	ElementDTD * noeudDTD = elts[nomNoeudCourant];

	// verification de l'existance du noeud courant dans la dtd
	if (noeudDTD == NULL)
	{
		return false;
	}

	// vérification des attributs du noeud courant
  

	// vérification des sous-éléments
}

#include "dtd/dtd.tab.h" 
#include "xml/xml.tab.h"
#include <stdio.h>
#include <string.h>

#include "xml/structureXML/AbstractElement.h"
#include "xml/structureXML/AttributXML.h"
#include "xml/structureXML/Document.h"
#include "xml/structureXML/ElementBalise.h"
#include "xml/structureXML/ElementTexte.h"

#include "dtd/structureDTD/AttributDTD.h"
#include "dtd/structureDTD/DocumentDTD.h"
#include "dtd/structureDTD/ElementDTD.h"

int xmlparse();
int dtdparse();
extern int xmldebug;
extern int dtddebug;
extern char * sDtd;
extern FILE * dtdin;

int affichageEltXML(ElementBalise * eltXML)
{
  printf("<%s",eltXML->getNom());
  list<AttributXML>::iterator it;
  list<AttributXML> listAtts=eltXML->getLstAttributXML();
  for(it=listAtts.begin();it!=listAtts.end();it++)
  {
  	printf(" %s=\"%s\"",it->getNom(),it->getValeur());
  } 
  list<AbstractElement> listElts=eltXML->getLstAbstractElement();
  if(listElts->size()>0)
  {
  	printf(">");
  	list<AbstractElement>::iterator it2;
	for(it2=listElts.begin();it2!=listElts.end();it2++)
  	{
  		affichageEltXML(it2);
  	}
	printf("</%s>",eltXML->getNom());
  }
  else
  {
	printf("/>");
  }
}

int affichageDocXML(Document * dXML)
{
  ElementBalise * pEltBalise=dXML->getElementBalise();
  affichageEltXML(pEltBalise);
}

int main(int argc, char **argv)
{
  int err;

  Document * docXML;

  xmldebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = xmlparse(docXML);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);

  if(sDtd==NULL)
	printf("Aucun dtd associé\n", err);
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

  affichageDocXML(docXML);
  return 0;
}

int verifXml(DocumentDTD * dtd, Document * xml)
{
	ElementBalise * racine = xml->racine;
	set<ElementDTD> elts = dtd->getElementsDtd();

	string nomNoeudCourant = racineXml->getNom();


}

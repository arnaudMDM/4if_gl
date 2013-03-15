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

int main(int argc, char **argv)
{
  int err;

  xmldebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = xmlparse();
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

  return 0;
}

int verifXml(DocumentDTD * dtd, Document * xml)
{
	ElementBalise * racine = xml->racine;

	string * nomNoeudCourant = &racine->nom;
}

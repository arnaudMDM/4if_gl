%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "commun.h"
#include "structureXSL/ElementTextuel.h"
#include "structureXSL/ElementXSL.h"
#include "structureXSL/DocumentXSL.h"
#include <list>
#include "xsl.tab.h"


// ces trois fonctions devront changer de nom dans le cas où l'option -p est utilisée
int xslwrap(void);
void xslerror(DocumentXSL * docXSL, char *msg); 
int xsllex(void);

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace, cf commun.h */
   AbstractElementXSL * abstractElement; /* C est un element balise uniquement */
   list<AbstractElementXSL *> * lstAbstractElement; /* C est une liste */
   AttributXSL * attributXSL; 
}

%token EGAL SLASH SUP
%token <s> DATA VALEUR COMMENT NOM OSTYLESHEET FSTYLESHEET OTEMPLATE FTEMPLATE OAPPLYTEMPLATES
%type <abstractElement> element
%type <lstAbstractElement> contenu_opt  
%type <lstAbstractElement> ferme_contenu_et_fin
%type <s> ouvre_contenu ferme_contenu
%type <attributXSL> attributs_opt

/* Pour recuperer le document en entier */ 
%parse-param {DocumentXSL * docXSL}

%%

document
 : element misc_seq_opt {docXSL->setElementXSL((ElementXSL*)$1)}
 ;
misc_seq_opt
 : misc_seq_opt misc /*  si je ne veux pas stocker, je ne mets rien : { $$ = $1  }; $$->push_back(string($2)) }*/ 
 | /*vide*/ /* {$$ = new list<string>} */ 
 ;
misc
 : COMMENT
 ;

element
 : ouvre_contenu attributs_opt ferme_contenu_et_fin SUP {$$ = new ElementXSL(string($1),$3,$2);}
 | OAPPLYTEMPLATES attributs_opt SLASH SUP {$$ = new ElementXSL(string($1),new list<AbstractElementXSL*>(),$2);}
 ;

ouvre_contenu
 : OSTYLESHEET {$$ = $1;}
 | OTEMPLATE {$$ = $1;}
 ;

attributs_opt
 : NOM EGAL VALEUR {$$ = new AttributXSL(string($1),string($3));}
 | /*vide*/{$$ = NULL}
 ;

ferme_contenu_et_fin
 : SUP contenu_opt ferme_contenu { $$ = $2 }
 ;

 ferme_contenu
 : FSTYLESHEET
 | FTEMPLATE
 ;

contenu_opt /* Regle de construction en commentaire */
 : contenu_opt misc { $$ = $1 }
 | contenu_opt element  { $$ = $1 ; $$->push_back($2)} //  delete $2
 | contenu_opt DATA { $$ = $1 ; $$->push_back(new ElementTextuel(string($2)))} // delete $2
 | /*vide*/     { $$ = new list<AbstractElementXSL*>() }      
 ;

%%


int xslwrap(void)
{
  return 1;
}

void xslerror(DocumentXSL * docXSL, char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


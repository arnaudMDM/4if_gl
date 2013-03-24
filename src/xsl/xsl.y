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

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE
%token <s> ENCODING VALEUR DONNEES COMMENT NOM ENNOM DTD SYSTEM
%token <en> OBALISEEN OBALISESPECIALE FBALISEEN
%type <abstractElement> element
%type <lstAbstractElement> contenu_opt  
%type <lstAbstractElement> vide_ou_contenu
%type <lstAbstractElement> ferme_contenu_et_fin
%type <en> ouvre
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
 : ouvre attributs_opt vide_ou_contenu {printf("AAAA!");if( strcmp(($1->first).c_str(),"xsl") == 0 ) $$ = new ElementXSL($1->second,$3,$2) ; else printf("CCCC!");}
 ;
ouvre
 : OBALISEEN {$$ = $1}
 ;

attributs_opt
 : NOM EGAL VALEUR {$$ = new AttributXSL(string($1),string($3));}
 ;

vide_ou_contenu
 : SLASH SUP {$$=new list<AbstractElementXSL*>()} /*contenu vide*/
 | ferme_contenu_et_fin SUP { $$ = $1 }  /*contenu non vide*/
 ;
ferme_contenu_et_fin
 : SUP contenu_opt FBALISEEN { $$ = $2 }
 ;
contenu_opt /* Regle de construction en commentaire */
 : contenu_opt DONNEES { $$ = $1 ; $$->push_back(new ElementTextuel(string($2)))} // delete $2
 | contenu_opt misc { $$ = $1 }
 | contenu_opt element  { $$ = $1 ; $$->push_back($2)} //  delete $2
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


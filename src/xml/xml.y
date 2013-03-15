%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include "commun.h"
#include "xml.tab.h"

// ces trois fonctions devront changer de nom dans le cas où l'otion -p est utilisée
int xmlwrap(void);
void xmlerror(char *msg);
int xmllex(void);
char * sDtd;

%}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace, cf commun.h */
}

%token EGAL SLASH SUP SUPSPECIAL DOCTYPE
%token <s> ENCODING VALEUR DONNEES COMMENT NOM ENNOM DTD SYSTEM
%token <en> OBALISEEN OBALISE OBALISESPECIALE FBALISE FBALISEEN

%%

document
 : declarations element misc_seq_opt 
 ;
misc_seq_opt
 : misc_seq_opt misc
 | /*vide*/
 ;
misc
 : COMMENT
 ;

declarations
 : declarations declaration
 | /*vide*/
 ;
 
declaration
 : DOCTYPE NOM SYSTEM DTD SUP {sDtd=$4;}
 | DOCTYPE NOM NOM VALEUR SUP 
 ;

element
 : ouvre attributs_opt vide_ou_contenu  
 ;
ouvre
 : OBALISE
 | OBALISEEN
 ;
attributs_opt
 : attributs_opt NOM EGAL VALEUR
 | /*vide*/
 ;
vide_ou_contenu
 : SLASH SUP
 | ferme_contenu_et_fin SUP 
 ;
ferme_contenu_et_fin
 : SUP contenu_opt FBALISE
 ;
contenu_opt 
 : contenu_opt DONNEES
 | contenu_opt misc 
 | contenu_opt element
 | /*vide*/          
 ;

%%


int xmlwrap(void)
{
  return 1;
}

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


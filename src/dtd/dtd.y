%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>



void dtderror(char *msg);
int dtdwrap(void);
int dtdlex(void);

%}

%union { 
   char *s; 
}

%token ELEMENT ATTLIST SUP OUVREPAR FERMEPAR VIRGULE BARRE FIXED EMPTY ANY PCDATA AST PTINT PLUS CDATA
%token <s> DTDNOM TOKENTYPE DECLARATION DTDVALEUR

%%

main: dtd_list_opt
;

dtd_list_opt
: dtd_list_opt ATTLIST DTDNOM att_definition_opt SUP
| dtd_list_opt ELEMENT DTDNOM children SUP
| /* vide */
;

children
: choice card_opt
| seq card_opt
| OUVREPAR PCDATA FERMEPAR
;

choice
: OUVREPAR cp liste_choice FERMEPAR
;

cp
: DTDNOM card_opt
| choice card_opt
| seq card_opt
;

card_opt
: PTINT
| AST
| PLUS
| /*vide*/
;

seq
: OUVREPAR cp liste_seq_opt FERMEPAR
;

liste_choice
: liste_choice BARRE cp
| BARRE cp
;

liste_seq_opt
: liste_seq_opt VIRGULE cp
| /*vide*/

att_definition_opt
: att_definition_opt attribut
| /* vide */
;

attribut
: DTDNOM att_type defaut_declaration
;

att_type
: CDATA
| TOKENTYPE
| type_enumere
;

type_enumere
: OUVREPAR liste_enum_plus FERMEPAR
;

liste_enum_plus
: liste_enum BARRE DTDNOM
;

liste_enum
: DTDNOM
| liste_enum BARRE DTDNOM
;

defaut_declaration
: DECLARATION
| DTDVALEUR
| FIXED DTDVALEUR
;

%%

int dtdwrap(void)
{
  return 1;
}

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

%{

using namespace std;
#include <cstring>
#include <cstdio>
#include <cstdlib>



void yyerror(char *msg);
int yywrap(void);
int yylex(void);

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

int main(int argc, char **argv)
{
  int err;

  yydebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = yyparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);
  return 0;
}
int yywrap(void)
{
  return 1;
}

void yyerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

#include "dtd/dtd.tab.h" 
#include "xml/xml.tab.h"
#include <stdio.h>

int xmlparse();
int dtdparse();
extern int xmldebug;
extern char * sDtd;

int main(int argc, char **argv)
{
  int err;

  xmldebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = xmlparse();
  printf("coucou: %s",sDtd);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);
/*
 if(argc > 1) {
        FILE *file;
        file = fopen(argv[1], "r");

        if(!file) {
           fprintf(stderr, "Could not open %s \n", argv[1]);
           exit(1);
        }

        yyin = file;
        yyout = fopen("out.txt", "w");
    }
    yylex();
    fclose(yyin);
    fclose(yyout);
*/
  return 0;
}

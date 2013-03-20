all: analyseXSL
analyseXSL: *.l *.y makefile
	flex -Pxsl xsl.l
	bison -pxsl --debug --verbose --defines=xsl.tab.h xsl.y
	g++ -g -DYYDEBUG=1 -c lex.xsl.c xsl.tab.c
	mv *.o ../
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output


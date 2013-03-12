all: analyseXML
analyseXML: *.l *.y makefile
	flex -Pxml xml.l
	bison -pxml --debug --verbose --defines=xml.tab.h xml.y
	g++ -g -DYYDEBUG=1 lex.xml.c xml.tab.c
	mv *.o ../
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output


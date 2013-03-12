all: analyseDTD
analyseDTD: *.l *.y makefile
	flex -Pdtd dtd.l
	bison -pdtd --debug --verbose --defines=dtd.tab.h dtd.y
	g++ -g -DYYDEBUG=1 -c lex.dtd.c dtd.tab.c
	mv *.o ../
clean:
	-rm -rf *.tab.c lex.*.c *.tab.h *.output


all: analyse
analyse: *.o analyseXML analyseDTD main.c makefile
	g++ -g -o analyse *.o main.c
analyseXML: xml/*.l xml/*.y xml/makefile
	cd xml; make all
analyseDTD: dtd/*.l dtd/*.y dtd/makefile
	cd dtd, make all
clean:
	-rm -rf *.o analyse
	cd xml; make clean
	cd dtd; make clean

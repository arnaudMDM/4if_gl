XMLO=lex.xml.o xml.tab.o
DTDO=dtd.tab.o lex.dtd.o

XMLSTRUCTPATH=xml/structureXML/
XMLSTRUCT=$(XMLSTRUCTPATH)AttributXML.h $(XMLSTRUCTPATH)ElementBalise.cpp $(XMLSTRUCTPATH)ElementTexte.h $(XMLSTRUCTPATH)AbstractElement.h $(XMLSTRUCTPATH)Document.cpp $(XMLSTRUCTPATH)ElementBalise.h $(XMLSTRUCTPATH)makefile $(XMLSTRUCTPATH)AttributXML.cpp $(XMLSTRUCTPATH)Document.h $(XMLSTRUCTPATH)ElementTexte.cpp

DTDSTRUCTPATH=dtd/structureDTD/
DTDSTRUCT=$(DTDSTRUCTPATH)AttributDTD.cpp $(DTDSTRUCTPATH)DocumentDTD.cpp $(DTDSTRUCTPATH)ElementDTD.cpp $(DTDSTRUCTPATH)makefile $(DTDSTRUCTPATH)AttributDTD.h $(DTDSTRUCTPATH)DocumentDTD.h $(DTDSTRUCTPATH)ElementDTD.h

XSLSTRUCTPATH=dtd/structureXSL/
XSLSTRUCT=$(XSLSTRUCTPATH)DocumentXSL.cpp $(XSLSTRUCTPATH)AbstractElementXSL.h  $(XSLSTRUCTPATH)AttributXSL.cpp  $(XSLSTRUCTPATH)AttributXSL.h  $(XSLSTRUCTPATH)DocumentXSL.h  $(XSLSTRUCTPATH)ElementTextuel.cpp  $(XSLSTRUCTPATH)ElementTextuel.h  $(XSLSTRUCTPATH)ElementXSL.cpp  $(XSLSTRUCTPATH)ElementXSL.h 

EXEC=analyse

all: $(EXEC)
#$(EXEC): analyseXML analyseDTD analyseXSL structureXML structureDTD structureXSL main.c makefile
$(EXEC): analyseXML analyseDTD structureXML structureDTD main.c makefile
	g++ -g -o $(EXEC) *.o main.c -lboost_regex
analyseXML: xml/*.l xml/*.y xml/makefile
	cd xml; make all
analyseDTD: dtd/*.l dtd/*.y dtd/makefile
	cd dtd; make all
#analyseXSL: xsl/*.l xsl/*.y dtd/makefile
#	cd xsl; make all
structureXML: $(XMLSTRUCT)
	cd xml/structureXML; make all
structureDTD: $(DTDSTRUCT)
	cd dtd/structureDTD; make all
#structureXSL: $(XSLSTRUCT)
#	cd xsl/structureXSL; make all
clean:
	rm -rf *.o $(EXEC)
	cd xml; make clean
	cd dtd; make clean
	cd $(XMLSTRUCTPATH); make clean
	cd $(DTDSTRUCTPATH); make clean

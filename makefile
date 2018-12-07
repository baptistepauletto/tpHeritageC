ECHO= @echo
RM= rm
COMP= g++
EDL= g++
CPPFLAGS= -ansi -pedantic -g -Wall -std=c++11 -D MAP
EDLFLAGS=
RMFLAGS= -f
INT= Catalogue.h TrajetSimple.h TrajetCompose.h CollectionTrajet.h main.h
REAL= $(INT:.h=.cpp)
OBJ= $(REAL:.cpp=.o)
LIBS=
INCPATH=
LIBPATH=
EFFACE= clean
EXE= executable
DATE= 19.11
AUTHOR= Baptiste & Felix
YEAR= 2018
EMAIL= baptiste.pauletto@insa-lyon.fr felix.fonteneau@insa-lyon.fr

.PHONY: $(EFFACE)

$(EXE) : $(OBJ)
	$(ECHO) "Edition de liens de <$(EXE)>"
	$(EDL) -o $(EXE) $(OBJ) $(LIBS)

%.o : %.cpp %.h
	$(ECHO) "Compilation de <$(<)>"
	$(COMP) $(CPPFLAGS) $(INCPATH) -c $<

Catalogue.o : Trajet.h CollectionTrajet.h

TrajetSimple.o : Trajet.h

TrajetCompose.o : Trajet.h CollectionTrajet.h

CollectionTrajet.o : Trajet.h

$(EFFACE) :
	$(ECHO) "Suppression des fichiers"
	$(RM) $(RMFLAGS) $(OBJ) $(EXE) core

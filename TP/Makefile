CC            = gcc
CXX           = g++
DEFINES       = 
CFLAGS        =  -O2 -Wall -W -Wextra $(DEFINES)
CXXFLAGS      =  -O2 -Wall -W -Wextra -pedantic  $(DEFINES)
INCPATH       = -I.
LINK          = g++
LFLAGS        =  -Wl,-O1
LIBS          = $(SUBLIBS)  -L/usr/lib -lm
COPY          = cp -f
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

TESTFILE = Classe_point.cpp

OBJECTS_DIR   = ./

####### Files

OBJECTSG       = Classe_point.o \
		Classe_poly.o \
		main_Graphe.o
OBJECTSP       = Classe_point.o \
        main_Point.o

DESTDIR       = 
TARGETG        = graphe.exe
TARGETP        = point.exe


####### Build rules

all: $(TARGETG) $(TARGETP)

$(TARGETG):  $(OBJECTSG)  
	$(LINK) $(LFLAGS) -o $(TARGETG) $(OBJECTSG) $(OBJCOMP) $(LIBS)

$(TARGETP):  $(OBJECTSP)  
	$(LINK) $(LFLAGS) -o $(TARGETP) $(OBJECTSP) $(OBJCOMP) $(LIBS)

clean: 
	-$(DEL_FILE) $(OBJECTSG)
    -$(DEL_FILE) $(OBJECTSP)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGETG) 



####### Compile
Classe_point.o: $(TESTFILE) Classe_point.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Classe_point.o Classe_point.cpp

Classe_poly.o: Classe_poly.cpp Classe_poly.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Classe_poly.o Classe_poly.cpp


main_Graphe.o: main_Graphe.cpp Classe_poly.h Classe_point.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main_Graphe.o main_Graphe.cpp

main_Point.o: main_Point.cpp Classe_point.h
    $(CXX) -c $(CXXFLAGS) $(INCPATH) -o main_Point.o main_Point.cpp

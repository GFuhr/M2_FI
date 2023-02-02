CC=g++
CFLAGS=-std=c++11 -O2 -Wall -Wextra -I.
SRC=..
OBJ=./obj
DEPS_TD1 = $(SRC)/Classe_capteurs.h
DEPS_TD2 = $(SRC)/Classe_capteurs.h $(SRC)/Classe_derived.h
DEPS_TD3 = $(SRC)/Classe_capteurs.h $(SRC)/Classe_derived.h $(SRC)/Classe_infra.h
OBJS_TD1 = $(OBJ)/Classe_capteurs.o $(OBJ)/main_capteurs.o
OBJS_TD2 = $(OBJ)/Classe_capteurs.o $(OBJ)/Classe_derived.o $(OBJ)/main_derived.o
OBJS_TD3 = $(OBJ)/Classe_capteurs.o $(OBJ)/Classe_derived.o $(OBJ)/Classe_infra.o $(OBJ)/main_infra.o

$(OBJ)/%.o: $(SRC)/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tp1.exe: $(OBJS_TD1) $(DEPS_TD1)
	$(CC) -o $@ $^ $(CFLAGS) 

tp2.exe: $(OBJS_TD2) $(DEPS_TD2)
	$(CC) -o $@ $^ $(CFLAGS) 

tp3.exe: $(OBJS_TD2) $(DEPS_TD2)
	$(CC) -o $@ $^ $(CFLAGS)

tp1 : td1.exe
tp2 : td1.exe
tp3 : td1.exe

clean : 
	rm $(OBJ)/*.o ./tp*.exe

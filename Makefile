SRC = src
INC = include
OBJ = obj
BIN = bin
DAT = datos
COM = g++ 

# **** letras ****
$(BIN)/letras: $(OBJ)/letras.o $(OBJ)/bolsa_letras.o $(OBJ)/conjunto_letras.o $(OBJ)/Letra.o $(OBJ)/lista_palabras.o
	$(COM) -o $(BIN)/letras $(OBJ)/letras.o $(OBJ)/bolsa_letras.o $(OBJ)/conjunto_letras.o $(OBJ)/Letra.o $(OBJ)/lista_palabras.o

$(OBJ)/letras.o : $(SRC)/letras.cpp
	$(COM) -c -o $(OBJ)/letras.o $(SRC)/letras.cpp -I$(INC) 

$(OBJ)/bolsa_letras.o : $(SRC)/bolsa_letras.cpp
	$(COM) -c -o $(OBJ)/bolsa_letras.o $(SRC)/bolsa_letras.cpp -I$(INC) 

$(OBJ)/conjunto_letras.o : $(SRC)/conjunto_letras.cpp	
	$(COM) -c -o $(OBJ)/conjunto_letras.o $(SRC)/conjunto_letras.cpp -I$(INC) 
	
$(OBJ)/lista_palabras.o : $(SRC)/lista_palabras.cpp	
	$(COM) -c -o $(OBJ)/lista_palabras.o $(SRC)/lista_palabras.cpp -I$(INC) 

$(OBJ)/Letra.o : $(SRC)/Letra.cpp
	$(COM) -c -o $(OBJ)/Letra.o $(SRC)/Letra.cpp -I$(INC) 

execP:
	./$(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras.txt 8 P

execL:
	./$(BIN)/letras $(DAT)/spanish.txt $(DAT)/letras.txt 8 L

# **** testlista_palabras ****
testlista_palabras:
	$(COM) -c -o $(OBJ)/testlista_palabras.o $(SRC)/testlista_palabras.cpp -I$(INC) 
	$(COM) -c -o $(OBJ)/lista_palabras.o $(SRC)/lista_palabras.cpp -I$(INC) 
	$(COM) -o $(BIN)/testlista_palabras $(OBJ)/testlista_palabras.o $(OBJ)/lista_palabras.o 

exec_testlista_palabras:
	./$(BIN)/testlista_palabras $(DAT)/spanish.txt

# **** cantidad ****
cantidad:
	$(COM) -c -o $(OBJ)/Letra.o $(SRC)/Letra.cpp -Iinclude
	$(COM) -c -o $(OBJ)/conjunto_letras.o $(SRC)/conjunto_letras.cpp -Iinclude
	$(COM) -c -o $(OBJ)/lista_palabras.o $(SRC)/lista_palabras.cpp -Iinclude
	$(COM) -o $(BIN)/cantidad $(SRC)/cantidad.cpp $(OBJ)/Letra.o $(OBJ)/conjunto_letras.o $(OBJ)/lista_palabras.o -I$(INC) 

exec_cantidad:
	./$(BIN)/cantidad $(DAT)/spanish.txt $(DAT)/letras.txt $(DAT)/salida.txt

all:  $(BIN)/letras 

# **** Documentacion ****
doxy:
	doxygen doc/doxys/Doxyfile
	firefox doc/html/index.html

# **** Limpieza ****
clean :
	-rm $(OBJ)/* $(BIN)/* $(DAT)/*

mrproper : clean
	-rm -rf doc/html/* $(OBJ)/* 

/**
@brief Programa principal con el cual jugar a letras
@author Luis Miguel Aguilar Gonzalez
@author Francisco Álvarez Terribas
**/
#include "bolsa_letras.h"
#include "conjunto_letras.h"
#include "lista_palabras.h"
#include <vector>
#include <utility>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

/**
@brief Obtiene la puntuacion de una palabra
@param Palabra a puntuar
@param Conjunto de letras con las puntuaciones de estas
@return Puntuacion de la palabra
**/
int puntuacion_palabra(const string &palabra, conjunto_letras &C){
    int puntuacion = 0;
    for(int i = 0; i < palabra.length(); i++)
        puntuacion += C.getPuntuacion(toupper(palabra[i]));

    return puntuacion;
}

/**
@brief Obtiene el numero de veces que un caracter está repetido en un vector
@param Vector de letras
@param Caracter a comprobar
@return Numero de veces que el caracter está repetido
**/
int contador(const vector<char> &letras,const char &caracter){
    vector<char> aux = letras;
    int contador = 0;

    while(!aux.empty()){
        if(aux.back() == caracter)
            contador++;
        aux.pop_back();
    }
    return contador;
}

/**
@brief Dice si se puede formar una palabra con las letras dadas
@param Palabra a evaluar
@param Conjunto de letras 
@return Booleano indicando si se puede formar o no
**/
bool esta_contenida(const string &palabra, vector<char> &letras){

    vector<char> esta;
    bool unavez;
    bool esta_dentro = false;
    
    for(int i = 0; i < palabra.size(); i++){
        vector<char> aux = letras;
        unavez = false;
        for(int j = 0; j < letras.size() && !unavez; j++){
            if(palabra[i] == tolower(aux.back()) && !unavez){
                esta.push_back(aux.back());
                unavez = true;
            }
            aux.pop_back();     
        }
    } 

    bool buena_Cantidad = true;

    for(int i = 0; i < letras.size(); i++){
        for(int j = 0; j < esta.size(); j++){
            if(letras[i] == esta[j]){
                if(contador(letras, esta[j]) < contador(esta, letras[i])){
                    buena_Cantidad = false;
                }
            }
        }
    }

    if(esta.size() == palabra.size() && buena_Cantidad)
        esta_dentro = true;

    return esta_dentro;
}

/**
@brief Obtiene un vector con las palabras validas formadas
@param Conjunto de letras
@param Longitud de las palabras que se formarán 
@param Lista con las palabras validas
@return Vector de palabras creadas
**/
vector<string> obtener_palabras(vector<char> &letras, int longitud, const lista_palabras &D){
    
    lista_palabras aux = D;
    vector<char> letras_aux = letras;
    vector<string> palabras_longitud = aux.palabras_longitud(longitud);
    vector<string> palabras_resultado;
   
    while(!palabras_longitud.empty()){
        if(esta_contenida(palabras_longitud.back(),letras_aux)){
            palabras_resultado.push_back(palabras_longitud.back());
            letras_aux.pop_back();
        }

        palabras_longitud.pop_back();
    }
    
    return palabras_resultado;
}

/**
@brief Programa principal
@param Fichero con palabras
@param Fichero con Letras
@param Número de letras a sacar de la bolsa
@param Modo de juego L (la palabra más larga) y P (la palabra de mayor puntuación)
**/
int main(int argc, char const *argv[]){

    if(argc != 5){
        cout << "Los parametros son:" << endl;
        cout << "1.-El fichero con las palabras" << endl;
        cout << "2.-El fichero con las letras" << endl;
        cout << "3.-El número de letras" << endl;
        cout << "4.-El modo de juego L (la palabra más larga) y P (la palabra de mayor puntuación)" << endl;
        return 1;
    }

    ifstream f1(argv[1]);
    if(!f1){
        cout << "No puedo abrir el fichero " << argv[1] << endl;
        return 1;
    }

    ifstream f2(argv[2]);
    if(!f2){
        cout << "No puedo abrir el fichero " << argv[2] << endl;
        return 1;
    }

    if(!isdigit(*argv[3])){
        cout << "\"" << argv[3] << "\"" << " no es un número " << endl;
        return 1;
    }

    if( (strcmp(argv[4],"L") != 0) && (strcmp(argv[4],"P") != 0) ) {
        cout << "El cuarto argumento tiene que ser L o P " << endl;
        return 1;
    }


    conjunto_letras C;
    lista_palabras D;
    vector<pair<char,int> > puntuaciones;
    bool continuarjuego;
    string aux;

    while(!f1.eof())
    	f1 >> D;

    f2 >> aux >> aux >> aux;
    while(!f2.eof())
        f2 >> C;

    bolsa_letras B(C);

    

    
    if(strcmp(argv[4],"L") == 0){
        do{
            cout << endl;
            bolsa_letras Bolsa(B);
            vector<char> letras = Bolsa.extraerLetras(atoi(argv[3]));

            cout << "Las letras son: ";
            for (auto const& l : letras)
                cout << l << "      ";
            cout << endl;

            string respuesta;
            string mejor;
            cout << "Dime tu solución: ";
            cin >> respuesta;

            if(esta_contenida(respuesta, letras)){
                if(D.Esta(respuesta))
                    cout << respuesta << "    Puntuación: " << respuesta.size() << "\n\n";
                else {
                    cout << respuesta << " no existe" << "\n\n";
                    respuesta = "";
                }
            } else {
                cout << "\"" << respuesta << "\" no se puede crear con las letras dadas\n";
                respuesta = ""; 
            }

            cout << "Mis soluciones son:" << endl;
            bool palabras_resultado = true;
            for(int i = atoi(argv[3]); i > 0 && palabras_resultado; i--){
                vector<string> resultado;
                resultado = obtener_palabras(letras, i, D);
                if(!resultado.empty()){
                    palabras_resultado = false;
                    while(!resultado.empty()){
                        cout << resultado.back() << "    Puntuación: " << resultado.back().size() << endl;
                        mejor = resultado.back();
                        resultado.pop_back();
                    }
                }
            }

            if(mejor == "")
                cout << "No existen soluciones con estas letras." << endl;

            if(mejor.size() == respuesta.size())
                cout << "Hay un empate" << endl;
            else if(mejor.size() > respuesta.size())
                cout << "Mejor solución: " << mejor << endl;
            else cout << "Mejor solución: " << respuesta << endl;

            char continuar;

            do {
                cout << "¿Quieres seguir jugando[S/N]? ";
                cin >> continuar;
            } while( (continuar != 'S') && (continuar != 'N') );
            
            if(continuar == 'S')
                continuarjuego = true;
            else continuarjuego = false;

        } while(continuarjuego);
        
    } else {
        do{
            cout << "******Puntuaciones Letras*******" << endl;
            for(char i = 'A'; i <= 'Z'; i++)
                cout << i << "\t\t" << C.getPuntuacion(i) << endl;

            cout << endl;
            bolsa_letras Bolsa(B);
            vector<char> letras = Bolsa.extraerLetras(atoi(argv[3]));

            cout << "Las letras son: ";
            for (auto const& l : letras)
                cout << l << "      ";
            cout << endl;

            pair<string,int> respuesta, mejor;

            cout << "Dime tu solución: ";
            cin >> respuesta.first;

            if(esta_contenida(respuesta.first, letras)){
                if(D.Esta(respuesta.first)){
                    respuesta.second = puntuacion_palabra(respuesta.first,C);
                    cout << respuesta.first << "    Puntuación: " << respuesta.second << "\n\n";
                } else {
                    cout << respuesta.first << " no existe" << "\n\n";
                    respuesta.first = "";
                }
            } else {
                cout << "\"" << respuesta.first << "\" no se puede crear con las letras dadas\n";
                respuesta.first = ""; 
            }

            cout << "Mis soluciones son:" << endl;
            bool palabras_resultado = true;
            vector<string> palabras;
            for(int i = atoi(argv[3]); i > 0; i--){
                vector<string> resultado;
                resultado = obtener_palabras(letras, i, D);
                for (auto const& l : resultado)
                        palabras.push_back(l);
            }                    

            vector<string> mayores;
            mejor.second = 0;
            for (auto const& l : palabras){
                int punt =  puntuacion_palabra(l,C);

                if(mejor.second < punt){
                    mejor.first  = l;
                    mejor.second = punt;
                    mayores.clear();
                    mayores.push_back(l);
                } else if(mejor.second == punt){
                    mejor.first  = l;
                    mejor.second = punt;
                    mayores.push_back(l);
                }
            }
            
            for (auto const& l : mayores)
                cout << l << "    Puntuación: " << mejor.second << endl;
            
            if(mejor.first == "")
                cout << "No existen soluciones con estas letras." << endl;

            if(mejor.second == respuesta.second)
                cout << "Hay un empate" << endl;
            else if(mejor.second > respuesta.second)
                cout << "Mejor solución: " << mejor.first << endl;
            else cout << "Mejor solución: " << respuesta.first << endl;

            char continuar;

            do {
                cout << "¿Quieres seguir jugando[S/N]? ";
                cin >> continuar;
            } while( (continuar != 'S') && (continuar != 'N') );
            
            if(continuar == 'S')
                continuarjuego = true;
            else continuarjuego = false;

            cout << endl;

        } while(continuarjuego);

    }

}
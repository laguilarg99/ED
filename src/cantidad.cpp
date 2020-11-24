/**    
@brief Programa para comprobar el numero de letras de un archivo concreto 
@author Luis Miguel Aguilar Gonzalez
@author Francisco Álvarez Terribas
**/
#include "lista_palabras.h"
#include "conjunto_letras.h"
#include <iomanip>
#include <queue>
using namespace std;


/**
@brief Programa principal
@param Fichero con palabras
@param Fichero con Letras
@return Fichero con la frecuencia de las letras
**/
int main(int argc, char const *argv[])
{

    string CABECERA;

    if(argc != 4){
        cout << "Los parametros son:" << endl;
        cout << "1.-El fichero con las palabras" << endl;
        cout << "2.-El fichero con las letras" << endl;
        cout << "3.-El fichero de salida" << endl;
        return 0;
    }

    ifstream spanish(argv[1]);
    if(!spanish){
        cout << "No puedo abrir el fichero " << argv[1] << endl;
        return 0;
    }

    lista_palabras D;

    cout <<"Cargando lista_palabras..." <<endl;
    while(!spanish.eof())
    	spanish >> D;

    cout << "Lectura lista de palabras completada" << endl;

    ifstream letras(argv[2]);
    if(!letras){
        cout << "No puedo abrir el fichero " << argv[2] << endl;
        return 0;
    }
    
    conjunto_letras L;

    getline(letras, CABECERA, '\n');

    cout <<"Cargando letras..." <<endl;
    while(!letras.eof())
    	letras >> L;

    cout << "Lectura lista de conjunto de letras completada" << endl;
    
    cout << "Creando archivo de salida con la frecuencia de las letras..." << endl; 

    queue<pair<char, float> > datos_finales;

    conjunto_letras::iterator itrC = L.begin();
    lista_palabras::iterator itrL = D.begin();
    
    float tamanio_frecuencia= 0;

    for(int i = 0; i < D.size(); i++){
        for(int j = 0; j < (*itrL).size(); j++){
            tamanio_frecuencia++;
        }        
        ++itrL;
    }

    while(itrC != L.end()){
        
        float contador_por_letra = 0;   
        float resultado = 0;
        lista_palabras::iterator finales = D.begin();
        
        for(int i = 0; i < D.size(); i++){
            for(int j = 0; j < (*finales).size(); j++){
                if((*finales)[j] == tolower((*itrC).first)){
                    contador_por_letra++;
                }
            }
            ++finales;
        }

        resultado = (contador_por_letra/tamanio_frecuencia)*100;
        datos_finales.push(make_pair((*itrC).first, resultado));
        ++itrC;
    }
    
    ofstream salida(argv[3]);

    salida << "#Letra" << " " << "Cantidad" << endl;
    while(!datos_finales.empty()){
        salida << datos_finales.front().first << setw(10) << datos_finales.front().second << endl;
        datos_finales.pop();
    }

    cout << "Completada creacion del archivo de salida." << endl;

    return 0;
    
 
}

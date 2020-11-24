#include "lista_palabras.h"
using namespace std;

/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES 
/*____________________________________________________________ */
/*____________________________________________________________ */

lista_palabras::lista_palabras(){}

int lista_palabras::size()const{
    return datos.size();
}

vector<string> lista_palabras::palabras_longitud(int palabras_longitud){

    set<string>::iterator p;
    vector<string> longitud;
    
    for(p = datos.begin(); p != datos.end(); p++){
	string palabra = *p;
        if(palabra.size() == palabras_longitud)
            longitud.push_back(palabra);
    }

    return longitud;

}

bool lista_palabras::Esta(string palabra){
    return datos.find(palabra) != datos.end();    
}

set<string> lista_palabras::getDatos()const{
    return datos;
}


std::istream & operator>>(istream & is, lista_palabras &D){
    
    string palabra;
    is >> palabra; 
    D.datos.insert(palabra);
    return is;
}

std::ostream & operator<<(ostream & os, const lista_palabras &D){

    set<string>::iterator itr;
    for(itr = D.datos.begin(); itr != D.datos.end(); itr++)
        cout << *itr << endl;
    return os;
}

/*
************************************************************
Iterador
************************************************************
*/

lista_palabras::iterator::iterator(){}

string lista_palabras::iterator::operator*(){
    return *it;
}

lista_palabras::iterator & lista_palabras::iterator::operator++(){
    
    set<string>::iterator recorrer = it;
    it++;
    return *this;
}

bool lista_palabras::iterator::operator==(const iterator &i){
    return it == i.it;
}


bool lista_palabras::iterator::operator!=(const iterator &i){
    return it != i.it;
}

lista_palabras::iterator lista_palabras::begin(){
    lista_palabras::iterator itr;
    itr.it = datos.begin();
    return itr;
}

lista_palabras::iterator lista_palabras::end(){
    lista_palabras::iterator itr;
    itr.it = datos.end();
    return itr;
}


#include "conjunto_letras.h"
using namespace std;

conjunto_letras::conjunto_letras(){}

bool conjunto_letras::empty(){
      return letras.empty();
}

Letra conjunto_letras::getLetra(char l){
    return letras[l];
}

conjunto_letras conjunto_letras::getConjunto(){
    return *this;
}

double conjunto_letras::getCantidad(char l){
    return letras[l].getCantidad();
}

int conjunto_letras::getPuntuacion(char l){
    return letras[l].getPuntuacion();
}

void conjunto_letras::setLetra(Letra letra){
    letras[letra.getLetra()] = letra;
}

void conjunto_letras::setCantidad(char l, double c){
    letras[l].setCantidad(c);
}

void conjunto_letras::setPuntuacion(char l, int p){
    letras[l].setPuntuacion(p);
}

std::istream & operator>>(istream & is, conjunto_letras &conjunto){
    Letra l;
    is >> l; 
    conjunto.setLetra(l);
    return is;
}

std::ostream & operator<<(ostream & os, conjunto_letras &conjunto){
    for (auto const& l : conjunto)
        cout << l.second;
    return os;
}

/*
************************************************************
Iterador
************************************************************
*/

conjunto_letras::iterator::iterator(){}

pair<const char, Letra> conjunto_letras::iterator::operator*(){
    return *it;
}

conjunto_letras::iterator & conjunto_letras::iterator::operator++(){
    map<char,Letra>::iterator recorrer = it;
    it++;
    return *this;
}

bool conjunto_letras::iterator::operator==(const iterator &i){
    return it == i.it;
}


bool conjunto_letras::iterator::operator!=(const iterator &i){
    return it != i.it;
}

conjunto_letras::iterator conjunto_letras::begin(){
    conjunto_letras::iterator itr;
    itr.it = letras.begin();
    return itr;
}

conjunto_letras::iterator conjunto_letras::end(){
    conjunto_letras::iterator itr;
    itr.it = letras.end();
    return itr;
}
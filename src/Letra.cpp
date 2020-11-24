#include "Letra.h"
using namespace std;

Letra::Letra(){}

void Letra::setLetra(char l){
    letra.first = l;
}

void Letra::setPuntuacion(int p){
    letra.second.first = p;
}

void Letra::setCantidad(double c){
    letra.second.second = c;
}

char Letra::getLetra() const{
    return letra.first;
}

int Letra::getPuntuacion() const{
    return letra.second.first;
}

double Letra::getCantidad() const{
    return letra.second.second;
}

std::istream & operator>>(istream & is, Letra &L){
    char l;
    double c;
    int p;    
    is >> l; 
    is >> c;
    is >> p;
    L.setLetra(l);
    L.setCantidad(c);
    L.setPuntuacion(p);
    return is;
}

std::ostream & operator<<(ostream & os, const Letra &L){
    cout << L.getLetra() << " " << L.getCantidad() << " " << L.getPuntuacion() << endl;
    return os;
}

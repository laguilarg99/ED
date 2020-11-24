#include "bolsa_letras.h"
using namespace std;

/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES 
/*____________________________________________________________ */
/*____________________________________________________________ */

bolsa_letras::bolsa_letras(){}

bolsa_letras::bolsa_letras( conjunto_letras& v){    
    if(!v.empty()){
        for (auto const& x : v){
            insertarLetra(x.second.getLetra(),x.second.getCantidad()); 
        }
    }
}

bolsa_letras::bolsa_letras(bolsa_letras& B){
    this->bolsa = B.bolsa;
}

bolsa_letras bolsa_letras::getBolsa(){
    return *this;
}

void bolsa_letras::insertarLetra(char l, double c){
    for(int i = 0; i < c; i++)
        bolsa.push_back (l);
}

void bolsa_letras::insertarLetra(char l){
    bolsa.push_back (l);
}

void bolsa_letras::insertarConjunto(conjunto_letras &v){
    if(!v.empty()){
        for (auto const& x : v){
            insertarLetra(x.second.getLetra(),x.second.getCantidad()); 
        }
    }
}

vector<char> bolsa_letras::extraerLetras(int n){
    vector<char> aux;
    srand(time(0));
    for(int i = 0; i < n && !bolsa.empty(); i++){
        int pos = rand() % bolsa.size();
        aux.push_back(bolsa[pos]);
        bolsa.erase(bolsa.begin() + pos);
    } 
    return aux;
}

std::istream & operator>>(istream & is, bolsa_letras &B){
    char l;
    is >> l;
    B.insertarLetra(l);
    return is;
}

std::ostream & operator<<(ostream & os, bolsa_letras &B){
    for (auto const& l : B)
        cout << l << " " << endl;
    return os;
}

/*
************************************************************
Iterador
************************************************************
*/

bolsa_letras::iterator::iterator(){}

const char bolsa_letras::iterator::operator*(){
    return *it;
}

bolsa_letras::iterator & bolsa_letras::iterator::operator++(){
    vector<char>::iterator recorrer = it;
    it++;
    return *this;
}

bool bolsa_letras::iterator::operator==(const iterator &i){
    return it == i.it;
}


bool bolsa_letras::iterator::operator!=(const iterator &i){
    return it != i.it;
}

bolsa_letras::iterator bolsa_letras::begin(){
    bolsa_letras::iterator itr;
    itr.it = bolsa.begin();
    return itr;
}

bolsa_letras::iterator bolsa_letras::end(){
    bolsa_letras::iterator itr;
    itr.it = bolsa.end();
    return itr;
}
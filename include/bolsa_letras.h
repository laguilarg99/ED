#ifndef __bolsa_letras_h__
#define __bolsa_letras_h__

#include "conjunto_letras.h"
#include <cstdlib>
#include <ctime> 
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

    /**
    @brief Contenedor para almacenar los caracteres con los que posteriormente se formarán palabras
    @author Luis Miguel Aguilar Gonzalez
    @author Francisco Álvarez Terribas
    **/
class bolsa_letras{
    private:
        vector<char> bolsa;

    public:

        /**
        @brief constructor base de la clase
        */
        bolsa_letras(); 

        /**
        @brief constructor el cual crea un objeto bolsa_letras a partir de un conjunto_letras
        @param Conjunto de letras
        */
        bolsa_letras( conjunto_letras& v);

        /**
        @brief constructor copia el cual crea un objeto bolsa_letras a partir de otra bolsa de letras 
        @param Bolsa de letras
        */
        bolsa_letras(bolsa_letras& B);

        /**
        @brief constructor copia el cual crea un objeto bolsa_letras a partir de otra bolsa de letras 
        @return La bolsa de letras actual
        */
        bolsa_letras getBolsa();

        /**
        @brief inserta en la bolsa de letras un conjunto_letras
        @param Conjunto de letras
        */        
        void insertarConjunto( conjunto_letras &v);

        /**
        @brief introduce en la bolsa un caracter un numero determinado de veces
        @param caracter que se va a introducir
        @param numero de veces que se introduce el caracter
        */
        void insertarLetra(char l, double c);
        
        /**
        @brief introduce un caracter en la bolsa
        @param caracter que se va a introducir
        */
        void insertarLetra(char l);

        /**
        @brief Extrae letras de la bolsa de la bolsa de letras
        @param int n, numero de letras que se van a extraer
        @return vector de letras extraidas
        */
        vector<char> extraerLetras(int n);

        /**
        @brief Lee de un flujo de entrada 
        @param is flujo de entrada
        @param D el objeto donde se realiza la lectura.
        @return el flujo de entrada
        **/
        friend istream & operator>>(istream & is, bolsa_letras &B);

        /**
        @brief Escribe en un flujo de salida 
        @param os flujo de salida
        @param D el objeto conjunto_letras que se escribe
        @return el flujo de salida
        **/
        friend ostream & operator<<(ostream & os, const bolsa_letras &B);
    
    /**
    @brief Iterator para recorrer la bolsa de letras
    */

    class iterator {
      private:
          vector<char>::iterator it;

      public:

        /**
        @brief Constructor por defecto.
        */
        iterator();

        /**
        @brief devuelve el valor del puntero.
        @return devuelve el elemento.
        */
        const char operator *();

        /**
        @brief Mueve el iterador una posicion hacia delante
        @return iterator de la posicion contigua
        */
        iterator & operator ++();

        /**
        @brief compara dos iteradores
        @return verdadero o falso
        */
        bool operator ==(const iterator &i);

        /**
        @brief devuelve si son distintos
        @return verdadero o false
        */
        bool operator !=(const iterator &i);


        friend class bolsa_letras;
    };

    /**
    @brief calcula el inicio de la bolsa de letras
    @return el iterador que señala al comienzo del contenedor.
    */
    iterator begin();

    /**
    @brief calcula el final de la bolsa de letras
    @return el iterador que señala al final del contenedor.
    */
    iterator end();
};

/**
@brief Lee de un flujo de entrada 
@param is flujo de entrada
@param D el objeto donde se realiza la lectura.
@return el flujo de entrada
**/
std::istream & operator>>(istream & is, bolsa_letras &B);

/**
@brief Escribe en un flujo de salida 
@param os flujo de salida
@param D el objeto conjunto_letras que se escribe
@return el flujo de salida
**/
std::ostream & operator<<(ostream & os, bolsa_letras &B);

#endif /*bolsa_letras*/
#ifndef __lista_palabras_h__
#define __lista_palabras_h__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

    /**
    @brief Contenedor para almacenar una lista de palabras
    @author Luis Miguel Aguilar Gonzalez
    @author Francisco Álvarez Terribas
    **/
class lista_palabras{
    public:

        /**
        @brief Construye un lista_palabras vacío.
        **/
        lista_palabras();

        /**
        @brief Devuelve el numero de palabras en el lista_palabras
        **/
        int size() const;

        /**
        @brief Obtiene todas las palabras en el lista_palabras de una longitud dada
        @param longitud la longitud de las palabras de salida
        @return un vector con las palabras de longitud especificada en el parámetro de entrada
        **/
        vector<string> palabras_longitud(int longitud);

        /**
        @brief Indica si una palabra está en el lista_palabras o no
        @param palabra la palabra que se quiere buscar
        @return true si la palabra esta en el lista_palabras. false en caso contrario
        **/
        bool Esta(string palabra);

        /**
        @brief Devuelve el contenedor de palabras
        **/
        set<string> getDatos()const;

        friend istream & operator>>(istream & is, lista_palabras &D);
        friend ostream & operator<<(ostream & os, const lista_palabras &D);

        /**
        @brief Iterator para recorrer el set de palabras
        **/

        class iterator {

            public:

                /**
                @brief Construye un iterator que apunta al vacio.
                **/
                iterator();

                /**
                @brief devuelve el valor del puntero.
                @return devuelve el elemento.
                **/
                string operator *();

                /**
                @brief Mueve el iterador una posicion hacia delante
                @return iterator de la posicion contigua
                **/
                iterator & operator ++();

                /**
                @brief compara dos iteradores
                @return verdadero o falso
                **/
                bool operator ==(const iterator &i);

                /**
                @brief devuelve si son distintos
                @return verdadero o false
                **/
                bool operator !=(const iterator &i);


                friend class lista_palabras;

            private:
                set<string>::iterator it;
        };

        /**
        @brief calcula el inicio del set de palabras
        @return el iterador que señala al comienzo del contenedor.
        **/
        iterator begin();

        /**
        @brief calcula el final del set de palabras
        @return el iterador que señala al final del contenedor.
        **/
        iterator end();
        
    private:

        set<string> datos;
};

/**
@brief Lee de un flujo de entrada un lista_palabras
@param is flujo de entrada
@param D el objeto donde se realiza la lectura.
@return el flujo de entrada
**/
std::istream & operator>>(istream & is, lista_palabras &D);

/**
@brief Escribe en un flujo de salida un lista_palabras
@param os flujo de salida
@param D el objeto lista_palabras que se escribe
@return el flujo de salida
**/
std::ostream & operator<<(ostream & os, const lista_palabras &D);

#endif /*lista_palabras*/
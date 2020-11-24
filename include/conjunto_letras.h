#ifndef __CONJUNTO_LETRAS_H__
#define __CONJUNTO_LETRAS_H__

#include <fstream>
#include <iostream>
#include "Letra.h"
#include <map>
using namespace std;

    /**
    @brief Contenedor para almacenar un conjunto de Letras
    @author Luis Miguel Aguilar Gonzalez
    @author Francisco Álvarez Terribas 
    **/
class conjunto_letras{
  private:  
      map<char,Letra> letras;
      
  public:

    /**
    @brief Constructor por defecto
    */
    conjunto_letras();

    /**
    @brief Indica si el conjunto está vacío o no
    @return Booleano
    */
    bool empty();
    
    /**
    @brief Devuelve un elemento del map de Letras
    @param char l, caracter de la letra objeto dentro del map
    @return Letra objeto de dicho tipo contenido en el map
    */
    Letra getLetra(char l);

    /*
    @brief Devuelve el objeto conjunto de letras
    @return conjunto_letras completo 
    */
    conjunto_letras getConjunto();

    /**
    @brief devuelve el atributo cantidad de una letra
    @return double cantidad
    */
    double getCantidad(char l);

    /**
    @brief devuelve el atributo de puntuacion de una letra
    @return int puntuacion
    */
    int getPuntuacion(char l);

    /**
    @brief introduce una letra en el map
    @param Letra letra objeto
    */
    void setLetra(Letra letra);

    /**
    @brief modifica la cantidad en el map de una letra
    @param char l caracter a modificar
    @param double c nueva cantidad
    */
    void setCantidad(char l, double c);

    /**
    @brief modifica el atributo puntuacion de un elemento del map
    @param char l caracter a modificar
    @param int p nueva puntuacion para dicho caracter
    */
    void setPuntuacion(char l, int p);

    friend istream & operator>>(istream & is, conjunto_letras &D);
    friend ostream & operator<<(ostream & os, conjunto_letras &D);
    
    /**
    @brief Iterator para recorrer el map de letras
    */

    class iterator {
      public:

        /**
        @brief Constructor por defecto.
        */
        iterator();

        /**
        @brief devuelve el valor del puntero.
        @return devuelve el elemento.
        */
        pair<const char, Letra> operator *();

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


        friend class conjunto_letras;

        private:
          map<char,Letra>::iterator it;
    };

    /**
    @brief calcula el inicio del map de letras
    @return el iterador que señala al comienzo del contenedor.
    */
    iterator begin();

    /**
    @brief calcula el final del map de letras
    @return el iterador que señala al final del contenedor.
    */
    iterator end();
};

/**
@brief Lee de un flujo de entrada un conjunto_letras
@param is flujo de entrada
@param D el objeto donde se realiza la lectura.
@return el flujo de entrada
**/
std::istream & operator>>(istream & is, conjunto_letras &D);

/**
@brief Escribe en un flujo de salida un conjunto_letras
@param os flujo de salida
@param D el objeto conjunto_letras que se escribe
@return el flujo de salida
**/
std::ostream & operator<<(ostream & os, conjunto_letras &D);

#endif 
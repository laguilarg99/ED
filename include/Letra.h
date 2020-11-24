#ifndef __LETRA_H__
#define __LETRA_H__

#include <iostream>
#include <utility>
using namespace std;

    /**
    @brief Contenedor para almacenar un caracter, su puntuación y la cantidad de veces que aparece
    @author Luis Miguel Aguilar Gonzalez
    @author Francisco Álvarez Terribas
    **/
class Letra{
  private:        
    pair <char,pair<int,double> > letra;
    
  public:
    /**
    @brief Constructor por defecto
    */
    Letra();

    /**
    @brief establece un nuevo atributo, letra de la clase
    @param char l caracter del objeto
    */
    void setLetra(char l);

    /**
    @brief establece un nuevo atributo, puntuacion de la clase
    @param int p caracter del objeto
    */
    void setPuntuacion(int p);

    /**
    @brief establece un nuevo atributo, cantidad de veces que se repite dicha letra
    @param double c numero de veces que aparece
    */
    void setCantidad(double c);
    
    /**
    @brief devuelve el atributo letra de la clase
    @return char l caracter del objeto
    */
    char getLetra() const;

    /**
    @brief devuelve el atributo puntuacion de la clase
    @return int p puntuacion el caracter
    */
    int getPuntuacion() const;

    /**
    @brief devuelve el atributo cantidad de veces que aparece el caracter
    @return double c cantidad de repeticiones del caracter
    */
    double getCantidad() const;


    friend istream & operator>>(istream & is, Letra &D);
    friend ostream & operator<<(ostream & os, const Letra &D);
};

/**
@brief Lee de un flujo de entrada una Letra
@param is flujo de entrada
@param L el objeto donde se realiza la lectura.
@return el flujo de entrada
**/
std::istream & operator>>(istream & is, Letra &L);

/**
@brief Escribe en un flujo de salida una Letra
@param os flujo de salida
@param L el objeto Letra que se escribe
@return el flujo de salida
**/
std::ostream & operator<<(ostream & os, const Letra &L);

#endif/*Letra*/
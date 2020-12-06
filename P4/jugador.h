/**
 * @Archivo jugador.h
 * @Contiene Clase Jugador y estructura Apuesta
 */

#ifndef __JUGADOR__
#define __JUGADOR__

#include "persona.h"

#include <list>
#include <fstream>

using std::list;

/**
 * La estructura Apuesta define el objeto Apuesta, el cual utilizaremos en
 * nuestro programa.
 */

struct Apuesta{
    
    int tipo,/** < define el tipo de apuesta que representa el objeto. 
            * Puede tomar 4 valores:
            * 
            * 1. Apuesta sencilla. Se apuesta a un número entre 0 y 36, y si sale, se gana 35 a 1 (se 
            * puede apostar y ganar al 0).
            *  
            * 2. Apuesta rojo o negro. Se apuesta a un color y se paga 1 a 1. Si sale el cero, se pierde.
            * 
            * 3. Apuesta par o impar. Se apuesta par o impar y se paga 1 a 1. Si sale el cero, se 
            * pierde.
            * 
            * 4. Apuesta alto o bajo. Bajo es entre 1 y 18; alto entre 19 y 36. Se paga 1 a 1. Si sale el 
            * cero, se pierde.
            * 
            */
    cantidad; /**< define la cuantia apostada por el Jugador */
    string valor;/**< contiene el valor al que apostó la cantidad el jugador en cuestión.*/
};

/**
 * La clase Jugador hereda todos los metodos de la clase Persona y añade algunos
 * metodos apropiados.
 */

class Jugador : public Persona{
    private:
        int dinero_;                /**< Almacena el dinero del jugador.*/
        string codigo_;             /**< Almacena el codigo identificador del jugador.*/
        list <Apuesta> apuestas_;   /**< Se trata de una lista de estructuras <Apuesta>
                                    * donde se almacenan todas las apuestas que quiera 
                                    * realizar el Jugador en cuestión.
                                    */
    public: 
        /**
         * @function Jugador()
         * @param <string> dni
         * @param <string> codigo 
         * @param <string> nombre, 
         * @param <string> apellidos
         * @param <int> edad
         * @param <string> direccion 
         * @param <string> localidad
         * @param <string> provincia
         * @param <string> pais 
         * @param <int> dinero
         * @see Persona() en persona.h
         * 
         * Constructor de clase, Nos pide como parametros todas sus variables pero solo
         * se requiere el DNI y codigo como valor obligatorio al generar un objeto 
         * de esta clase, todos los demas atributos tienen un valor predeterminado.
         */
        Jugador(string dni, string codigo, string nombre="\0", string apellidos="\0", int edad=0 ,string direccion="\0",string localidad="\0", string provincia="\0", string pais="\0", int dinero=1000);
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada codigo_
         * 
         * @function setCodigo() 
         * @param <string> codigo
         * Recibe un <string> codigo y lo asigna a la variable codigo_.
         * 
         * @function getCodigo() 
         * Nos retorna el valor constante de codigo_.
         * @return <string> codigo_
         */
        inline void setCodigo(string codigo){codigo_=codigo;}
        inline string getCodigo()const{return codigo_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada dinero_
         * 
         * @function setDinero() 
         * @param <int> dinero
         * Recibe un <int> dinero y lo asigna a la variable dinero_.
         * 
         * @function getDinero() 
         * Nos retorna el valor constante de dinero_.
         * @return <int> dinero_
         */

        inline void setDinero(int dinero){dinero_=dinero;}
        inline int getDinero()const{return dinero_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada apuestas_
         * 
         * @function setApuestas() 
         * 
         * Limpia la lista de apuestas (apuestas_) y lee un fichero (DNI.txt), 
         * siendo DNI el dni del jugador, guardando las apuestas de dicho fichero
         * en la lista apuestas_.
         * El fichero seguira la estructura de:
         * CÓDIGO­APUESTA,VALOR,CANTIDAD
         * CÓDIGO­APUESTA,VALOR,CANTIDAD
         * 
         * @function getApuestas() 
         * Nos retorna el valor constante de apuestas_.
         * @return < list<Apuesta> > apuestas_
         */
        
        void setApuestas();
        inline list<Apuesta> getApuestas()const{return apuestas_;}
};

#endif
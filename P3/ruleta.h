/**
 * @Archivo ruleta.h
 * @Contiene Clase Ruleta
 */

#ifndef __RULETA__
#define __RULETA__
#include "crupier.h"
#include "jugador.h"
#include <fstream>
#include <string>

/**
 * La clase Ruleta define los metodos necesarios para llevar una partida
 * @see Class Jugador en jugador.h
 * @see Class Crupier en crupier.h
 */


class Ruleta{
    private:
        int banca_,     /**< Almacena el dinero que guarda la banca */
        bola_;          /**< Almacena el valor de la bola al tirar de la ruleta*/
        list <Jugador> jugadores_;  /**< Almacena una lista de jugadores que
                                     * participan en dicha ruleta.
                                     */
        Crupier crupier_;           /**< Almacena los datos del crupier encargado
                                     * de dicha ruleta
                                     */
    public:

        /**
         * @function Ruleta()
         * @param <Crupier> crupier 
         * 
         * Constructor de clase, Nos pide como parametro un Crupier.
         */
        Ruleta(Crupier cuprier);
    
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada banca_
         * 
         * @function setBanca()
         * @param <int> banca
         * 
         * Recibe un <int> banca, comprueba si es menor a cero y en caso
         * de que cumpla dicha propiedad retorna false, en caso contrario 
         * lo asigna a la variable banca_ y retorna true.
         * 
         * @function getBanca() 
         * Simplemente nos retorna el valor constante de banca_.
         * @return <int> banca_ 
         */
        inline bool setBanca(int banca){if(banca<0)return false; banca_=banca; return true;}
        inline int getBanca()const{return banca_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada bola_
         * 
         * @function setBola()
         * @param <int> bola
         * 
         * Recibe un <int> bola, comprueba si es mayor a 36 o menor a cero y en caso
         * de que cumpla dicha propiedad retorna false, en caso contrario 
         * lo asigna a la variable bola_ y retorna true.
         * 
         * @function getBola() 
         * Simplemente nos retorna el valor constante de bola_.
         * @return <int> bola_
         */
        inline bool setBola(int bola){if(bola>36||bola<0)return false; bola_=bola; return true;}
        inline int getBola()const{return bola_;}

        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada crupier_
         * 
         * @function setCrupier() 
         * @param <Crupier> crupier
         * Recibe un <Crupier> crupier y lo asigna a la variable crupier_.
         * 
         * @function getCrupier() 
         * Nos retorna el valor constante de crupier_.
         * @return <Crupier> crupier_
         */
        inline void setCrupier(Crupier crupier){crupier_=crupier;}
        inline Crupier getCrupier()const{return crupier_;}
    
        /**
         * @function getJugadores()
         * Nos retorna la lista como valor constante de jugadores_;
         * @return < list<Jugador> > jugadores_
         */
        inline list<Jugador> getJugadores()const{return jugadores_;}
    
        /**
         * @function addJugador()
         * @param <Jugador> jugador -> Será el jugador que añadamos a la lista.
         * @var <std::fstream> f <- nos servirá para crear con el fichero DNI.txt
         * 
         * Recibe un jugador como parametro y comprueba si no esta en la lista jugadores_,
         * en caso contrario retorna false.
         * Si no existe dicho jugador procede a crear un fichero con nombre DNI.txt, siendo
         * DNI el dni del jugador obtenido mediante la funcion getDNI() de la clase Persona,
         * si el fichero no puede ser creado devuelve false, si consigue crearlo, lo cierra
         * y añade al jugador en cuestion a la lista jugadores_, retornando true en este caso.
         * 
         * @return <bool> true || false
         */
        bool addJugador(Jugador jugador);
    
        /**
         * @function deleteJugador()
         * @param <string> DNI -> Nos servira para identificar al jugador que queremos borrar.
         * 
         * Recibe un DNI como parametro, primero comprobará si la lista jugadores_ esta vacia, en
         * caso afirmativo retornara -1 y no hará nada. En caso contrario recorrerá la lista de jugadores_
         * añadiendo todos los jugadores con DNI diferente al dado como parametro a una lista auxiliar.
         * 
         * Al terminar, comprobará si la lista auxiliar tiene diferente tamaño que jugadores_, si es así
         * el jugador habrá sido eliminado con exito, actualizará la lista jugadores_ y lo notificará 
         * por consola, retornará 1.
         * 
         * En caso contrario, significará que el jugador no se encontraba en la lista, por lo que notificará
         * por consola que no fue encontrado y retornara -2.
         *  
         * @return <int> 1||-1||-2
         */
        int deleteJugador(string DNI);
    
        /**
         * @function deleteJugador()
         * @param <Jugador> jugador -> Nos servira para identificar al jugador que queremos borrar.
         * 
         * Recibe un jugador como parametro, primero comprobará si la lista jugadores_ esta vacia, en
         * caso afirmativo retornara -1 y no hará nada. En caso contrario recorrerá la lista de jugadores_
         * añadiendo todos los jugadores con DNI diferente al del jugador dado como parametro a una 
         * lista auxiliar.
         * 
         * Al terminar, comprobará si la lista auxiliar tiene diferente tamaño que jugadores_, si es así
         * el jugador habrá sido eliminado con exito, actualizará la lista jugadores_ y lo notificará 
         * por consola, retornará 1.
         * 
         * En caso contrario, significará que el jugador no se encontraba en la lista, por lo que notificará
         * por consola que no fue encontrado y retornara -2.
         *  
         * @return <int> 1||-1||-2
         */
        int deleteJugador(Jugador jugador);
    
        /**
         * @function escribeJugadores()
         * @var <std::fstream> f <- nos servirá para abrir e interactuar con el fichero jugadores.txt
         * 
         * Abre un fichero "jugadores.txt", borrando todo su contenido previo.
         * Comprueba si pudo abrirse correctamente, en caso afirmativo escribe los datos de todos
         * los jugadores que esten guardados en jugadores_ en ese momento siguiendo el formato:
         * DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
         * DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
         * 
         * Si alguno de estos campos no tuviese un valor definido quedaria tal que:
         * DNI,código,nombre,,,,,,dinero
         * 
         * En caso de que no se pueda crear correctamente el archivo lo notificará por consola.
         */
        void escribeJugadores();
    
        /**
         * @function leeJugadores()
         * @var <std::fstream> f <- nos servirá para abrir e interactuar con el fichero jugadores.txt
         * @var <char*> dni
         * @var <char*> codigo
         * @var <char*> nombre
         * @var <char*> apellidos
         * @var <char*> direccion
         * @var <char*> localidad
         * @var <char*> provincia
         * @var <char*> pais
         * @var <char*> dinero
         * 
         * Primero limpia la lista jugadores_.
         * Abre el fichero "jugadores.txt" en modo lectura.
         * Comprueba si pudo abrirse correctamente, en caso afirmativo lee los datos de todos
         * los jugadores que esten guardados en dicho fichero siguiendo el formato:
         * DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
         * DNI,código,nombre,apellidos,dirección,localidad,provincia,país,dinero
         * 
         * Guarda los datos de cada jugador en la lista jugadores_.
         * 
         * En caso de que no se pueda abrir correctamente el archivo lo notificará por consola.
         */
        void leeJugadores();
    
        /** 
         * @function giraRuleta()
         * 
         * Notifica por consola que se procede a tirar de la ruleta, genera un valor aleatorio de 0 a 36
         * y lo asigna a la variable privada bola_ mediante el metodo setBola(), por ultimo comunica por
         * consola el valor de la variable mediante el metodo getBola(), el cual seria el numero ganador.
         */
        void giraRuleta();
    
        /**
         * @function getPremios()
         * 
         * @var < list<Apuesta> > aux <- Guarda la lista de apuestas de cada jugador para analizar cada
         *                                apuesta de una forma mas comoda.
         * @var <int> balance <- Guarda el balance de cada apuesta para actualizar banca_ y dinero_
         * 
         * Recorre la lista de jugadores_, cargando sus apuestas con el metodo setApuestas()
         * una vez cargadas las apuestas de un jugador las guarda en una variable auxiliar
         * < list<Apuesta> aux> y recorre esta lista, analizando cada apuesta dependiendo su
         * tipo, guardando el balance de cada apuesta en una variable <int> balance la cual nos
         * servirá para actualizar tanto el dinero del jugador (utilizando los metodos setDinero() 
         * y getDinero()) la banca (utlizando los metodos setBanca() y getBanca()).
         * 
         * Dependiendo del tipo de apuesta, utilizará los metodos apuesta1(), esRojo(), esPar() y esAlto()
         * @see struct Apuesta en jugador.h
         */
        void getPremios();

        /** 
         * @function apuesta1()
         * @param <int> valor <- El valor al que se hizo la apuesta.
         * 
         * Compara si el valor apostado y el valor de bola_ son iguales, si es así retorna true, en caso
         * contrario retornara false.
         *  
         * @return <bool> true || false
        */
        inline bool apuesta1(int valor){return getBola()==valor?true:false;}
        
        /**
         * @function esRojo()
         * @param <int> valor <- El valor al que se hizo la apuesta.
         * @var <int> rojos[] <- Es un array que contiene todos los numeros representados en rojo
         *                          en la ruleta. 
         * Compara si el valor apostado viene representado por el color rojo en la ruleta
         * mediante la comparacion de dicho valor con los valores rojos[].
         * Si pertenece al array devolverá true, en caso contrario devolverá false.
         * 
         * @return <bool> true || false
         */
        bool esRojo(int valor);
    
        /**
         * @function esPar()
         * @param <int> valor <- El valor al que se hizo la apuesta.
         * 
         * Comprueba si el valor es par o impar.
         * Si es par devolvera true, en caso contrario devolverá false.
         * 
         * @return <bool> true || false
         */
        bool esPar(int valor){return valor%2==0?true:false;}
    
        /**
         * @function esAlto()
         * @param <int> valor <- El valor al que se hizo la apuesta.
         * 
         * Comprueba si el valor es mayor de 18, si es así devolvera true, 
         * en caso contrario devolverá false.
         * 
         * @return <bool> true || false
         */
        bool esAlto(int valor){return valor>18?true:false;}
};

#endif
/**
 * @Archivo persona.h
 * @Contiene Clase persona (CLASE MADRE)
 */
#ifndef __PERSONA__
#define __PERSONA__
#include <iostream>
#include <string>
using std::string;

/**
 * La clase Persona nos servirá como molde para la posterior implementacion de las
 * clases Jugador y Crupier.
 */

class Persona{
    private:
        int edad_;  /**< Almacena la edad de la persona.*/
        string dni_,/**< Almacena el DNI de la persona, nos servirá como identificador.*/
        nombre_,    /**< Almacena el nombre de la persona.*/
        apellidos_, /**< Almacena los apellidos de la persona.*/
        direccion_, /**< Almacena la direccion de la persona.*/
        localidad_, /**< Almacena la localidad de la persona.*/
        provincia_, /**< Almacena la provincia de la persona.*/
        pais_;      /**< Almacena el pais de la persona.*/
    public:
        /**
         * @function Persona()
         * @param <string> dni
         * @param <string> nombre, 
         * @param <string> apellidos
         * @param <int> edad
         * @param <string> direccion 
         * @param <string> localidad
         * @param <string> provincia
         * @param <string> pais 
         * 
         * Constructor de clase, Nos pide como parametros todas sus variables pero solo
         * se requiere el DNI como valor obligatorio al generar un objeto de esta clase,
         * todos los demas atributos tienen un valor predeterminado.
         */
        Persona(string dni, string nombre="\0", string apellidos="\0", int edad=0 ,string direccion="\0",string localidad="\0", string provincia="\0", string pais="\0");
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada edad_
         * 
         * @function setEdad()
         * @param <int> edad
         * 
         * Recibe un <int> edad, comprueba si es igual o mayor a cero y en caso
         * de que cumpla dicha propiedad lo asigna a la variable edad_ y retorna true,
         * en caso contrario retornara false.
         * 
         * @function getEdad() 
         * @return <int> edad_
         * Simplemente nos retorna el valor constante de edad_.
         */
        inline bool setEdad(int edad){if(edad>=0){edad_=edad;return true;}else return false;}
        inline int getEdad()const{return edad_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada dni_
         * 
         * @function setDNI() 
         * @param <string> dni
         * Recibe un <string> dni y lo asigna a la variable dni_.
         * 
         * @function getDNI() 
         * Nos retorna el valor constante de dni_.
         * @return <string> dni_
         */
        inline void setDNI(string dni){dni_=dni;}
        inline string getDNI()const{return dni_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada nombre_
         * 
         * @function setNombre() 
         * @param <string> nombre
         * Recibe un <string> nombre y lo asigna a la variable nombre_.
         * 
         * @function getNombre() 
         * Nos retorna el valor constante de nombre_.
         * @return <string> nombre_
         */
        inline void setNombre(string nombre){nombre_=nombre;}
        inline string getNombre()const{return nombre_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada apellidos_
         * 
         * @function setApellidos() 
         * @param <string> apellidos
         * Recibe un <string> apellidos y lo asigna a la variable apellidos_.
         * 
         * @function getApellidos() 
         * Nos retorna el valor constante de apellidos_.
         * @return <string> apellidos_
         */
        inline void setApellidos(string apellidos){apellidos_=apellidos;}
        inline string getApellidos()const{return apellidos_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada direccion_
         * 
         * @function setDireccion() 
         * @param <string> direccion
         * Recibe un <string> direccion y lo asigna a la variable direccion_.
         * 
         * @function getDireccion() 
         * Nos retorna el valor constante de direccion_.
         * @return <string> direccion_
         */
        inline void setDireccion(string direccion){direccion_=direccion;}
        inline string getDireccion()const{return direccion_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada localidad_
         * 
         * @function setLocalidad() 
         * @param <string> localidad
         * Recibe un <string> localidad y lo asigna a la variable localidad_.
         * 
         * @function getLocalidad() 
         * Nos retorna el valor constante de localidad_.
         * @return <string> localidad_
         */
        inline void setLocalidad(string localidad){localidad_=localidad;}
        inline string getLocalidad()const{return localidad_;} 
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada provincia_
         * 
         * @function setProvincia() 
         * @param <string> provincia
         * Recibe un <string> provincia y lo asigna a la variable provincia_.
         * 
         * @function getProvincia() 
         * Nos retorna el valor constante de provincia_.
         * @return <string> provincia_
         */
        inline void setProvincia(string provincia){provincia_=provincia;}
        inline string getProvincia()const{return provincia_;}
        
        /**
         * Las siguientes dos funciones están dedicadas a definir y de devolver
         * el valor de la variable privada pais_
         * 
         * @function setPais() 
         * @param <string> pais
         * Recibe un <string> pais y lo asigna a la variable pais_.
         * 
         * @function getPais() 
         * Nos retorna el valor constante de pais_.
         * @return <string> pais_
         */
        inline void setPais(string pais){pais_=pais;}
        inline string getPais()const{return pais_;}
        
        /**
         * @function getApellidosyNombre()
         * 
         * nos retorna un string resultado de la concatenacion de las 
         * variables apellidos_ y nombre_  tal que "apellidos_, nombre_"
         * @return <string> (apellidos_ + ", " + nombre_)
         */
        inline string getApellidosyNombre()const {return apellidos_+", "+nombre_;}
        
        /**
         * @function mayor() 
         * Nos retorna un valor booleano true si la persona es mayor de edad 
         * (si edad_ es igual o mayor de 18) y false en caso contrario
         * @return <bool> true||false
         */
        inline bool mayor(){return (edad_>=18?true:false);}
};
#endif
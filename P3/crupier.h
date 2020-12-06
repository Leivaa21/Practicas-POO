/**
 * @Archivo crupier.h
 * @Contiene Clase Crupier
 */

#ifndef __CRUPIER__
#define __CRUPIER__
#include "persona.h"

/**
 * La clase Crupier hereda todos los metodos de la clase Persona y añade algunos
 * metodos apropiados.
 */
class Crupier : public Persona{
    private: 
        /**
         * La variable <string> codigo_ almacena el codigo identificador del crupier.
         */
        string codigo_;
    public:
        /**
         * @function Crupier()
         * @param <string> dni
         * @param <string> codigo 
         * @param <string> nombre, 
         * @param <string> apellidos
         * @param <int> edad
         * @param <string> direccion 
         * @param <string> localidad
         * @param <string> provincia
         * @param <string> pais 
         * 
         * Constructor de clase, Nos pide como parametros todas sus variables, 
         * todos los atributos tienen un valor predeterminado para facilitar
         * la declaración de esta clase como parametro de otras funciones.
         */
        Crupier(string dni="\0", string codigo="\0", string nombre="\0", string apellidos="\0", int edad=0 ,string direccion="\0",string localidad="\0", string provincia="\0", string pais="\0");
        
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
};
#endif
//Archivo persona.h -> Define la clase Persona.

#include <iostream>
#include <string>
using std::string;

class Persona{
    private:
    int edad_;
        string dni_, nombre_, apellidos_, direccion_, localidad_, provincia_, pais_;
    public:
        Persona(string dni, string nombre="\0", string apellidos="\0", int edad=0 ,string direccion="\0",string localidad="\0", string provincia="\0", string pais="\0");
        inline bool setEdad(int edad){if(edad>=0){edad_=edad;return true;}else return false;}
        inline int getEdad()const{return edad_;}
        inline void setDNI(string dni){dni_=dni;}
        inline string getDNI()const{return dni_;}
        inline void setNombre(string nombre){nombre_=nombre;}
        inline string getNombre()const{return nombre_;}
        inline void setApellidos(string apellidos){apellidos_=apellidos;}
        inline string getApellidos()const{return apellidos_;}
        inline void setDireccion(string direccion){direccion_=direccion;}
        inline string getDireccion()const{return direccion_;}
        inline void setLocalidad(string localidad){localidad_=localidad;}
        inline string getLocalidad()const{return localidad_;} 
        inline void setProvincia(string provincia){provincia_=provincia;}
        inline string getProvincia()const{return provincia_;}
        inline void setPais(string pais){pais_=pais;}
        inline string getPais()const{return pais_;}
        inline string getApellidosyNombre()const {return apellidos_+", "+nombre_;}
        inline bool mayor(){return (edad_>=18?true:false);}
};


/**
 * @Archivo persona.cc
 * @Contiene Codigo de persona.h
 */

#include "persona.h"

Persona::Persona(string dni, string nombre, string apellidos, int edad,string direccion,string localidad, string provincia, string pais){
    setDNI(dni);
    setNombre(nombre);
    setApellidos(apellidos);
    setEdad(edad);
    setDireccion(direccion);
    setLocalidad(localidad);
    setProvincia(provincia);
    setPais(pais);
}

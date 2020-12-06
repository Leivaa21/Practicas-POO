/**
 * @Archivo crupier.cc
 * @Contiene Codigo de crupier.h
 */

#include "crupier.h"
Crupier::Crupier(string dni, string codigo, string nombre, string apellidos, int edad,string direccion,string localidad, string provincia, string pais): Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
    setCodigo(codigo);
}
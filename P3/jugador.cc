/**
 * @Archivo jugador.cc
 * @Contiene Codigo de jugador.h
 */

#include "jugador.h"
#include <fstream>
#define MAX 255
Jugador::Jugador(string dni, string codigo, string nombre, string apellidos, int edad,string direccion,string localidad, string provincia, string pais, int dinero): Persona(dni, nombre, apellidos, edad, direccion, localidad, provincia, pais){
    setCodigo(codigo);
    setDinero(dinero);
}
void Jugador::setApuestas(){
    apuestas_.clear();
    string nombrefichero=getDNI()+".txt";
    std::fstream f;
    f.open(nombrefichero, std::fstream::in);
    if (f.is_open()){
        char tipo[MAX], valor[MAX], cantidad[MAX];
        //codigo leer apuestas
        while(f.getline(tipo, MAX,',')){
            f.getline(valor, MAX, ',');
            f.getline(cantidad, MAX, '\n');
            Apuesta a = {atoi(tipo), atoi(cantidad), valor};
            apuestas_.push_back(a);
        }
    }
    else{std::cout<<"ERROR: No se pudo abrir el fichero!\n"; exit(1);}
}
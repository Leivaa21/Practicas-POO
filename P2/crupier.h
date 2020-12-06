//Archivo crupier.h -> Define la clase Crupier.
#include "persona.h"

class Crupier : public Persona{
    private: 
        string codigo_;
    public:
        Crupier(string dni, string codigo, string nombre="\0", string apellidos="\0", int edad=0 ,string direccion="\0",string localidad="\0", string provincia="\0", string pais="\0");
        inline void setCodigo(string codigo){codigo_=codigo;}
        inline string getCodigo()const{return codigo_;}
};
//Archivo jugador.h -> Define la clase Jugador y la estructura Apuesta.
#include "persona.h"
#include <list>
#include <fstream>
using std::list;
struct Apuesta{
    int tipo, cantidad; //El tipo de apuesta viene definido por -> 1=Sencilla, 2=porColor, 3=ParImpar, 4=AltoBajo
    string valor;
};
class Jugador : public Persona{
    private:
        int dinero_;
        string codigo_;
        list <Apuesta> apuestas_;
    public: 
        Jugador(string dni, string codigo, string nombre="\0", string apellidos="\0", int edad=0 ,string direccion="\0",string localidad="\0", string provincia="\0", string pais="\0");
        inline void setCodigo(string codigo){codigo_=codigo;}
        inline string getCodigo()const{return codigo_;}
        inline void setDinero(int dinero){dinero_=dinero;}
        inline int getDinero()const{return dinero_;}
        inline list<Apuesta> getApuestas(){return apuestas_;}
        void setApuestas();
};


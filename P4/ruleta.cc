/**
 * @Archivo ruleta.cc
 * @Contiene Codigo de ruleta.h
*/

#include "ruleta.h"
#include <string.h>
#define MAX 255
#define BancaInicia 1000000
Ruleta::Ruleta(Crupier crupier){
    srand(time(NULL));
    setCrupier(crupier);
    setBanca(BancaInicia);
    bola_=-1;
    lanzamientos_=0;
}

bool Ruleta::setBola(int bola){
    if(bola>36||bola<0)return false; 
    bola_=bola;
    lanzamientos_++;
    return true;
}

bool Ruleta::addJugador(Jugador jugador){
    for (auto i = jugadores_.begin(); i!=jugadores_.end(); i++)
        if((*i).getDNI()==jugador.getDNI()){ 
            std::cout<<"ERROR: El jugador ya esta registrado!\n";
            return false;
        }
    std::fstream f;
    f.open(jugador.getDNI() + ".txt", std::fstream::out);
    if(!f.is_open()){
        std::cout<<"ERROR: El fichero no se pudo crear.\n";
        return false;
    }
    f.close();
    jugadores_.push_back(jugador);
    return true;
}
int Ruleta::deleteJugador(string DNI){
    if(jugadores_.size()==0){
        std::cout<<"La lista de jugadores se encuentra vacia\n";
        return -1;
    }
    std::list<Jugador> aux;
    for (auto i = jugadores_.begin(); i!=jugadores_.end(); i++)
        if(DNI!=(*i).getDNI()) aux.push_back(*i);
    if(aux.size()!=jugadores_.size()){
        std::cout<<"Jugador eliminado con exito\n";
        jugadores_=aux;
        return 1;

    }else{
        std::cout<<"Jugador no encontrado en la lista\n";
        return -2;
    }

}
int Ruleta::deleteJugador(Jugador jugador){
    if(jugadores_.size()==0){
        std::cout<<"La lista de jugadores se encuentra vacia\n";
        return -1;
    }
    std::list<Jugador> aux;
    for (auto i = jugadores_.begin(); i!=jugadores_.end(); i++){
        if(jugador.getDNI()!=(*i).getDNI()){
            aux.push_back(*i);
        }
    }
    if(aux.size()!=jugadores_.size()){
        std::cout<<"Jugador eliminado con exito\n";
        jugadores_=aux;
        return 1;

    }else{
        std::cout<<"Jugador no encontrado en la lista\n";
        return -2;
    }
}
bool Ruleta::escribeJugadores(){
    std::fstream f;
    f.open("jugadores.txt", std::fstream::out|std::fstream::trunc);
    if (f.is_open()){
        for (auto i = jugadores_.begin(); i!=jugadores_.end(); i++){
            f<<(*i).getDNI() + ',' +(*i).getCodigo() + ',' +(*i).getNombre() + ',' +(*i).getApellidos() + ',' +(*i).getDireccion() + ',' +(*i).getLocalidad() + ',' +(*i).getProvincia() + ',' +(*i).getPais()+',';
            f<<(*i).getDinero();
            f<<"\n";
        }
        return true;
    }
    else{std::cout<<"ERROR: No se pudo abrir el fichero!\n"; exit(1);return false;}
    
}
bool Ruleta::leeJugadores(){
    jugadores_.clear();
    std::fstream f;
    f.open("jugadores.txt", std::fstream::in);
    if(f.is_open()){
        char dni[MAX], codigo[MAX], nombre[MAX], apellidos[MAX], direccion[MAX], localidad[MAX], provincia[MAX], pais[MAX], dinero[MAX];
        while(f.getline(dni, MAX, ',')){
            f.getline(codigo, MAX, ',');
            f.getline(nombre, MAX, ',');
            f.getline(apellidos, MAX, ',');
            f.getline(direccion, MAX, ',');
            f.getline(localidad, MAX, ',');
            f.getline(provincia, MAX, ',');
            f.getline(pais, MAX, ',');
            f.getline(dinero, MAX, '\n');
            Jugador aux(dni, codigo, nombre, apellidos,0, direccion, localidad, provincia, pais, atoi(dinero));
            jugadores_.push_back(aux);
        }
        return true;
    }
    else {std::cout<<"ERROR: No se pudo abrir el fichero!\n";return false;}
}

void Ruleta::giraRuleta(){
    std::cout<<"Tirando de la ruleta...\n";
    setBola(rand()%37);
    std::cout<<"La bola cayó en el "<<getBola()<<"\n\n";
}

void Ruleta::getPremios(){
    for (auto i = jugadores_.begin(); i!=jugadores_.end(); i++){ //i es cada jugador
        (*i).setApuestas();
        std::list<Apuesta> aux=(*i).getApuestas();
        for (auto l = aux.begin(); l!=aux.end(); l++){ //l es una apuesta especifica de i
            Apuesta apuesta= *l;
            std::cout<<"El jugador "<<i->getCodigo()
                    <<" realiza una apuesta de tipo "<<apuesta.tipo;
            switch (apuesta.tipo){
                int balance,val;
                case 1:
                    val=stoi(apuesta.valor);
                    if( apuesta1( &val ) ) {
                        balance=apuesta.cantidad*35;
                        resApuesta(true, balance);
                    }
                    else{
                        balance = -apuesta.cantidad;
                        resApuesta(false, balance);
                    }
                    (*i).setDinero((*i).getDinero()+balance);
                    setBanca(getBanca()-balance);
                    break;
                case 2:
                    if(bola_==0){
                        balance=-apuesta.cantidad;
                        resApuesta(false, balance);
                    }
                    else if( (esRojo(&bola_)&&apuesta.valor=="rojo") || (!esRojo(&bola_)&&apuesta.valor=="negro") ){
                        balance=apuesta.cantidad;
                        resApuesta(true, balance);
                    }
                    else {
                        balance= -apuesta.cantidad;
                        resApuesta(false, balance);
                    }
                    (*i).setDinero((*i).getDinero()+balance);
                    setBanca(getBanca()-balance);
                    break;
                case 3:
                    if(bola_==0){
                        balance=-apuesta.cantidad;
                        resApuesta(false, balance);
                        }
                    else if( (esPar(&bola_)&&apuesta.valor=="par") || (!esPar(&bola_)&&apuesta.valor=="impar") ){
                        balance=apuesta.cantidad;
                        resApuesta(true, balance);
                    }
                    else { 
                        balance= -apuesta.cantidad;
                        resApuesta(false, balance);
                    }
                    (*i).setDinero((*i).getDinero()+balance);
                    setBanca(getBanca()-balance);
                    break;
                case 4:
                    if(bola_==0){
                        balance=-apuesta.cantidad;
                        resApuesta(true, balance);
                    }
                    else if( (esAlto(&bola_)&&apuesta.valor=="alto") || (!esAlto(&bola_)&&apuesta.valor=="bajo") ) {
                        balance=apuesta.cantidad;
                        resApuesta(true, balance);
                    }
                    else {
                        balance= -apuesta.cantidad;
                        resApuesta(false, balance);
                    }
                    (*i).setDinero((*i).getDinero()+balance);
                    setBanca(getBanca()-balance);
                    break;
            }
        }
        
    }

}
bool Ruleta::esRojo(int *valor)const {
    int rojos[18] = {1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36};
    for(int i=0; i<18; i++) if((*valor)==rojos[i]) return true;
    return false;
}

void Ruleta::getEstadoRuleta(int *nJugadores, int *totalDinero, int *lanzamientos, int *balanceBanca){
    (*nJugadores)=jugadores_.size();
    (*totalDinero)=0;
    for(auto i=jugadores_.begin(); i!=jugadores_.end(); i++)
        (*totalDinero)+=(*i).getDinero();
    (*totalDinero)+=getBanca();
    (*lanzamientos)=lanzamientos_;
    (*balanceBanca)=getBanca()-BancaInicia;
}

void resApuesta(bool status, int balance){
    if(status){
        std::cout
            <<" y gana "<<balance<<" €!\n"
            <<"La banca pierde "<<balance<<" €\n\n\n";
    }
    else {
        std::cout
            <<" y pierde "<<(-balance)<<" €!\n"
            <<"La banca gana "<<(-balance)<<" €\n\n\n";
    }
}
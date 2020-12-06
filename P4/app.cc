#include "app.h"

int showmenu(){
    std::cout
        <<"======================================\n"
        <<"-----------------Menu-----------------\n"
        <<"======================================\n"
        <<"1-) Cargar Jugadores\n"
        <<"2-) Guardar Jugadores\n"
        <<"3-) Ver estado de la ruleta actual\n"
        <<"4-) Tirar de la ruleta\n"
        <<"5-) Añadir un jugador\n"
        <<"6-) Eliminar un Jugador\n"
        <<"\n"
        <<"0-) Salir del programa\n\n"
        <<"Indique un metodo: ";
    int res;
    std::cin>>res;
    limpiaPantalla();
    return res;
}

void Opcion1(Ruleta *ruleta){
    std::cout<<"Procediendo a cargar los jugadores del archivo 'jugadores.txt'...\n";
    if(ruleta->leeJugadores())
        std::cout<<"Jugadores cargados con exito!\n";
    else 
        std::cout<<"No se pudo cargar los jugadores!\n";
}

void Opcion2(Ruleta *ruleta){
    std::cout<<"Procediendo a guardar los jugadores en el archivo 'jugadores.txt'...\n";
    if(ruleta->escribeJugadores())
        std::cout<<"Jugadores guardados con exito!\n";
    else 
        std::cout<<"No se pudo guardar los jugadores!\n";
}

void Opcion3(Ruleta *ruleta){
    std::cout<<"Procediendo a ver las estadisticas de la ruleta actual...\n";
    int nJugadores, dinero, lanzamiento, banca;
    ruleta->getEstadoRuleta(&nJugadores, &dinero, &lanzamiento, &banca);
    std::cout
    <<"Hay "<<nJugadores<<" jugando actualmente\n"
    <<"Hay "<<dinero<<" en la mesa\n"
    <<"Se han realizado "<<lanzamiento<<" lanzamientos durante el juego\n"
    <<"La banca lleva un balance de "<<banca<<" desde que inicio el juego\n";
    std::list <Jugador> jugadores = ruleta->getJugadores();
    int aux=1;
    for (auto i=jugadores.begin(); i!=jugadores.end(); i++){
        std::cout
        <<"El jugador "<<aux<<" (con codigo: "<<i->getCodigo() 
        <<") tiene "<<i->getDinero()<<" € en la mesa\n";
        aux++; 
    }
    std::cout<<"La banca tiene "<<ruleta->getBanca()<<" € en este momento\n";

}

void Opcion4(Ruleta *ruleta){
    ruleta->giraRuleta();
    int banca = ruleta->getBanca();
    ruleta->getPremios();
    int resBanca = ruleta->getBanca()-banca;
    if (ruleta->getBanca()>banca) 
        std::cout<<"Tras todas las apuestas, la banca ganó "<<resBanca<<" €!\n";
    else if(ruleta->getBanca()<banca)
        std::cout<<"Tras todas las apuestas, la banca perdió "<<-resBanca<<" €!\n";
    else std::cout<<"Tras todas las apuestas, la banca no perdió ni ganó nada\n";
}

void Opcion5(Ruleta *ruleta){
    std::cout<<"Rellene los datos del nuevo jugador\n"
    <<"Los campos con * son obligatorios\n"
    <<"Los campos no obligatorios puede saltarlos\n\n";
    string DNI="", codigo="", nombre, apellidos, direccion, localidad, provincia, pais;
    int edad, dinero;
    while(DNI==""||DNI=="\n"){
        std::cout<<"*DNI: ";
        std::cin>>DNI;
    }
    while(codigo==""||codigo=="\n"){
        std::cout<<"*Codigo: ";
        std::cin>>codigo;
    }
    std::cout<<"Nombre: ";
    std::cin>>nombre;

    std::cout<<"Apellido: ";
    std::cin>>nombre;

    std::cout<<"Edad: ";
    std::cin>>edad;

    std::cout<<"Direccion: ";
    std::cin>>direccion;

    std::cout<<"Localidad: ";
    std::cin>>localidad;

    std::cout<<"Provincia: ";
    std::cin>>provincia;

    std::cout<<"Pais: ";
    std::cin>>pais;

    std::cout<<"Dinero: ";
    std::cin>>dinero;

    Jugador newJugador(DNI, codigo, nombre, apellidos, edad, direccion, localidad, provincia, pais, dinero);
    if (ruleta->addJugador(newJugador)) 
        std::cout<<"Jugador registrado con exito\n";
}

void Opcion6(Ruleta *ruleta){
    std::cout<<"Introduzca el DNI del jugador que desea borrar :";
    string DNI;
    std::cin>>DNI;
    ruleta->deleteJugador(DNI);
}
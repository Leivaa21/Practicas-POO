#include "app.h"

#include <string>
#include <iostream>

using std::cout;

int main(){
    limpiaPantalla();
    int res=-1;
    Crupier crupier;
    Ruleta ruleta(crupier);
    std::list <Jugador> jugadores = ruleta.getJugadores();
    while(res!=0){
        res=showmenu();
        switch (res){
            case 1:
                Opcion1(&ruleta);
                break;
            case 2:
                Opcion2(&ruleta);
                break;
            case 3:
                Opcion3(&ruleta);
                break;
            case 4:
                Opcion4(&ruleta);
                break;
            case 5:
                Opcion5(&ruleta);
                break;
            case 6:
                Opcion6(&ruleta);
                break;
        }
    }
    getchar();

}
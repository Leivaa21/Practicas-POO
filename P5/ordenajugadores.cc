#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <string>

struct Jugador{
    int DNI;
};


struct dnisort{
    bool operator()(Jugador const &a, Jugador const &b){
        return a.DNI < b.DNI;
    }
};


int main(){
    srand(time(NULL));
    std::vector<Jugador> v;
    int n;
    std::cout<<"Hay "<<v.size()<<" jugadores en el vector\n\n";
    std::cout<<"Cuantos jugadores se quiere generar aleatoriamente? ";
    std::cin>>n;
    for(int i=0; i<n; i++){
        int DNI=rand()%1000000;
        Jugador aux;
        aux.DNI=DNI;
        v.push_back(aux);
    }
    std::cout<<"Hay "<<v.size()<<" jugadores en el vector\n\n";
    for(int i=0; i<v.size(); i++)std::cout<<"Jugador nº"<<i+1<<" con DNI= "<<v[i].DNI<<"\n\n";
    std::sort(v.begin(), v.end(), dnisort());
    std::cout<<"Vector de jugadores ordenado, nuevo orden: \n\n";
    std::cout<<"Hay "<<v.size()<<" jugadores en el vector\n\n";
    for(int i=0; i<v.size(); i++)std::cout<<"Jugador nº"<<i+1<<" con DNI= "<<v[i].DNI<<"\n\n";
    return 1;
}
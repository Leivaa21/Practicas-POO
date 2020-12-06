#include <iostream>
#include <ctime>
#include <cstdlib>

int main(){
    srand(time(NULL)); //inicializa la semilla random
    int guess=(rand()%6); //Numero random entre 0 y 5
    int number=-1; //inicializamos la variable que cambiará el usuario con un valor diferente a guess.
    std::cout<<"Try to guess the number from 0 to 5 ;)\n";
    while(guess!=number){
        std::cin>>number;
    }
    std::cout<<"Great! the number was "<<guess<<"\n";
    return 0;
}

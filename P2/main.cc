#include "persona.h"
#include <string>
#include <iostream>

int main(){
    Persona p("80162787J");
    Persona q(p);
    if(p.getDNI()==q.getDNI())std::cout<<"true";
    return 0;
}
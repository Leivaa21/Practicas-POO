#include "persona.h"
#include "crupier.h"
#include "jugador.h"
#include "ruleta.h"

#include <string>
#include <iostream>

int main(){
    Persona p("80162787J");
    Persona q(p);
    if(p.getDNI()==q.getDNI())std::cout<<"true";
    Crupier x("90540", "CODE");
    Ruleta rule(x);
    if(rule.getCrupier().getCodigo()==x.getCodigo()) std::cout<<"Hello!\n";
}
#ifndef __APP__
#define __APP__

#include <iostream>
#include <string>

#include "persona.h"
#include "crupier.h"
#include "jugador.h"
#include "ruleta.h"

inline void limpiaPantalla(){std::cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";}
int showmenu();
void Opcion1(Ruleta *ruleta);
void Opcion2(Ruleta *ruleta);
void Opcion3(Ruleta *ruleta);
void Opcion4(Ruleta *ruleta);
void Opcion5(Ruleta *ruleta);
void Opcion6(Ruleta *ruleta);
#endif
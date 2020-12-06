#include "dados.h"

int main(){
    Dados d;
    int select,gaux,saux,setd;
    do{
        select=-1;
        while(select<0||select>7){
            select=selectMenu();
        }
        switch (select){
        case 1: //get
            do{
                gaux=MenuGetDado();
                switch (gaux){
                case 1:
                    std::cout<<"Dado 1 = "<<d.getDado1()<<"\n";
                    break;
                case 2:
                    std::cout<<"Dado 2 = "<<d.getDado2()<<"\n";
                    break;
                case 3:
                    std::cout<<d;
                    break;
                }
            }while(gaux<1||gaux>3);
            break;
        case 2: //lanzar
            d.lanzamiento();
            break;
        case 3: //set
            do{
                saux=MenuSetDado();
                switch (saux){
                case 1:
                    std::cout<<"\nIntroduzca el valor para el dado 1: ";
                    std::cin>>setd;
                    if(d.setDado1(setd))std::cout<<"\nValor introducido con exito\n";
                    else std::cout<<"No se pudo definir el dado 1 como "<<setd<<"\n";
                    break;
                case 2:
                    std::cout<<"\nIntroduzca el valor para el dado 2: ";
                    std::cin>>setd;
                    if(d.setDado2(setd))std::cout<<"\nValor introducido con exito\n";
                    else std::cout<<"No se pudo definir el dado 2 como "<<setd<<"\n";
                    break;
        
                case 3: 
                    std::cin>>d;
                    break;
                }
            }while(saux<1||saux>3);
            break;
        case 4: //suma
            std::cout<<"La suma de los dados es = "<<d.getSuma()<<"\n";
            break;
        case 5: //NºLanzamientos
            std::cout<<"\n Se ha lanzado el dado 1 un total de "<<d.getLanzamientos1()<<" veces.\n";
            std::cout<<"\n Se ha lanzado el dado 2 un total de "<<d.getLanzamientos2()<<" veces.\n";
            break;
        case 6: //Medias
            std::cout<<"\n La media para el dado 1 es "<<d.getMedia1()<<".\n";
            std::cout<<"\n La media para el dado 2 es "<<d.getMedia2()<<".\n";
            break;
        case 7: //Vectores
            int v1[5];
            d.getUltimos1(v1);
            std::cout<<"\n Los ultimos valores para el dado 1 han sido = | ";
            for(int i=0; i<5; i++)  std::cout<<v1[i]<<" | ";
            std::cout<<"\n";
            int v2[5];
            d.getUltimos2(v2);
            std::cout<<"\n Los ultimos valores para el dado 2 han sido = | ";
            for(int i=0; i<5; i++)  std::cout<<v2[i]<<" | ";
            std::cout<<"\n\n\n";
            break;
        }
    }while(select!=0);
    return 0;
}
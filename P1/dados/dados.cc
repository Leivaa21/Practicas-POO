#include "dados.h"

Dados::Dados(){
    srand(time(NULL));
    d1_=1;
    d2_=1;
    l1_=0;
    l2_=0;
    t1_=0;
    t2_=0;
    v1_.resize(5,0);
    v2_.resize(5,0);
}
void Dados::lanzamiento(){
    setDado1((rand()%6)+1);
    setDado2((rand()%6)+1);
}
bool Dados::setDado1(int n){
    if(n>6||n<1) return false;
    d1_=n;
    l1_++;
    t1_+=d1_;
    for(int i=0; i<4; i++) v1_[4-i]=v1_[3-i];
    v1_[0]=d1_;
    return true;
}
bool Dados::setDado2(int n){
    if(n>6||n<1) return false;
    d2_=n;
    l2_++;
    t2_+=d2_;
    for(int i=0; i<4; i++) v2_[4-i]=v2_[3-i];
    v2_[0]=d2_;
    return true;
}
void Dados::getUltimos1(int *v){
    for(int i=0; i<5; i++) v[i]=v1_[i];
}
void Dados::getUltimos2(int *v){
    for(int i=0; i<5; i++) v[i]=v2_[i];
}
int selectMenu(){
    std::cout<<"---Menu Principal---\n";
    std::cout<<"\n1- Obtener valor de un/los dado/s";
    std::cout<<"\n2- Realizar lanzamiento de dados";
    std::cout<<"\n3- Setear un dado";
    std::cout<<"\n4- Sumar dados";
    std::cout<<"\n5- Ver nº Lanzamientos de cada dado";
    std::cout<<"\n6- Ver medias de los lanzamientos de cada dado";
    std::cout<<"\n7- Ultimos 5 valores de cada dado";
    std::cout<<"\n0- Cerrar programa\n";
    int n;
    std::cin>>n;
    return n;
}
int MenuGetDado(){
    std::cout<<"\n\n---¿Que dado quieres obtener?---\n";
    std::cout<<"\n1- Dado 1";
    std::cout<<"\n2- Dado 2";
    std::cout<<"\n3- Ambos dados\n";
    int n;
    std::cin>>n;
    return n;
}
int MenuSetDado(){
    std::cout<<"\n\n---¿Que dado quieres setear?---\n";
    std::cout<<"\n1- Dado 1";
    std::cout<<"\n2- Dado 2\n";
    int n;
    std::cin>>n;
    return n;
}

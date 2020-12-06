#include <iostream>
#include <vector>
#include <algorithm> 


void displayvector(std::vector<int> v){
    for( int i=0; i<v.size(); i++ ) std::cout<<v[i]<<" | ";
    std::cout<<"\n";
}


int main(){
    int n;
    std::cout<<"\nIntroduzca el tamaño del vector a crear: ";
    std::cin>>n;
    std::vector <int> v(n);
    for( int i=0; i<v.size(); i++ ) {
        std::cout<<"\nIntroduzca un valor entero: ";
        std::cin>>v[i];
    }
    std::cout<<"\n El vector que introduciste es: \n | ";
    displayvector(v);

    char r='\0';

    while(toupper(r)!='A'&&toupper(r)!='D'){
        std::cout<<"\n\n\n¿Como desea ordenarlo?\n"
            <<"A = Ascendente\n"
            <<"D = Descendente\n";
        std::cin>>r;

        sort(v.begin(),v.end());
        
        if(toupper(r)=='A'){
            std::cout <<"\n\n\n Vector ordenado:\n | ";    
            displayvector(v);
        }
        else{
            reverse(v.begin(), v.end());
            std::cout <<"\n\n\n Vector ordenado:\n | ";  
            displayvector(v);
        }

    }



    return 1;
}
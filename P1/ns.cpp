#include <iostream>

using namespace std;

namespace n1{
    int a; //Var n1::a
    int b; //Var n1::b
}
namespace n2{
    int a; //Var n2::a
    int b; //Var n2::b
}
int main(){
    int a=55;
    n1::a=0;
    n2::a=2;
    cout<< "n1::a= " << n1::a << "\n";
    cout<< "n2::a= " << n2::a << "\n";
    cout<< "a= " << a << "\n";
    return 0;
}
#include <iostream>
using namespace std;
template <class T> class MiClase{
    private:
        T x_, y_;
    public:
        MiClase (T a, T b){ x_=a; y_=b;};
        T div(){return x_/y_;};
};
int main(){
    MiClase <int> iobj(10,3);
    MiClase <float> fobj(3.3, 5.5);
    cout << "division entera = " << iobj.div() << endl;
    cout << "division real = " << fobj.div() << endl;
}
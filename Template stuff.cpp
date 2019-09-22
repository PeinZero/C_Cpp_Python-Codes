#include<iostream>
using namespace std ;

template<class T>
class var {
    T a;
    public:
        var(){}
        var(T o):a(o){}
        void display() {
            cout << a << endl ;
        }
};

template<class T> 
class car: public var<T> {
    public:
        car(int l):var<T>(l){}
};

int main(int argc, char const *argv[])
{
    car <int> p(1);
    p.display();
    return 0;
}

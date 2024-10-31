#include <iostream>
using namespace std;

class klasa{
    public:
        void pusta(){
            cout<<"coś";
        };
};

int main()
{
    //1 sposób.
    
    klasa pusta;
    pusta.pusta();
    
    //2 sposób.
    
    klasa obiekt;;
    klasa *wskaznik;
    wskaznik=&obiekt;
    wskaznik->pusta();
}
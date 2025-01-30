#include <iostream>
using namespace std;
template <class Nasza_klasa>

Nasza_klasa Metoda (Nasza_klasa liczba){
    Nasza_klasa liczba_iloczyn = (liczba * liczba);
    
    return liczba_iloczyn;
}

template < class Nasza_klasa >

Nasza_klasa a_plus_b_pluc_c(Nasza_klasa a, Nasza_klasa b, Nasza_klasa c){
    Nasza_klasa wynik = (a + b + c);
    cout << "Nasz wynik sumy = " << wynik << endl;
    
    return 0;
}

int main(int argc, const char * argv[]){
    double liczba1 = Metoda< double >(6.5);
    cout << "Nasz iloczyn = "<<liczba1 <<endl;
    
    int liczba2 = a_plus_b_pluc_c < int > (10,16,2);
    cout << liczba2 << endl;
    getchar();


    return 0;
}
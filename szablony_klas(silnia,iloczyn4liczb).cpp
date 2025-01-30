#include <iostream>
using namespace std;

template <class Nasza_klasa>
Nasza_klasa Silnia(Nasza_klasa liczba) {
    if (liczba <= 1) return 1;
    return liczba * Silnia(liczba - 1);
}

template <class Nasza_klasa>
Nasza_klasa iloczyn_4_liczb(Nasza_klasa a, Nasza_klasa b, Nasza_klasa c, Nasza_klasa d) {
    Nasza_klasa wynik = (a * b * c * d);
    return wynik;
}

int main(int argc, const char * argv[]) {
    int liczba1 = Silnia<int>(5);
    cout << "Nasza silnia = " << liczba1 << endl;

    int liczba2 = iloczyn_4_liczb<int>(5, 3, 4, 5);
    cout << "Iloczyn 4 liczb = " << liczba2 << endl;

    return 0;
}

#include <iostream>
using namespace std;
#include <cmath>

int main() {
    double liczba1, liczba2;

    cout << "Podaj pierwsza liczbe: ";
    cin >> liczba1;

    cout << "Podaj druga liczbe: ";
    cin >> liczba2;

    double suma = liczba1 + liczba2;
    double roznica = liczba1 - liczba2;
    double iloczyn = liczba1 * liczba2;
    
    if (liczba2 != 0) {
        double iloraz = liczba1 / liczba2;
        double modulo = fmod(liczba1, liczba2);

        cout << "Suma: " << suma << endl;
        cout << "Roznica: " << roznica << endl;
        cout << "Iloczyn: " << iloczyn << endl;
        cout << "Iloraz: " << iloraz << endl;
        cout << "Modulo: " << modulo << endl;
    } else {
        cout << "Nie mozna dzielic przez zero." << endl;
    }

    return 0;
}
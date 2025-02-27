#include <iostream>
using namespace std;

bool pobierzDlugosc(const string& komunikat, double& wartosc) {
    cout << komunikat;
    cin >> wartosc;

    if (wartosc < 0) {
        cout << "Blad: Wprowadzona wartosc nie moze byc ujemna." << endl;
        return false;
    }

    return true;
}

int main() {
    double a, b, h;

    if (!pobierzDlugosc("Podaj dlugosc pierwszej podstawy (a): ", a)) {
        cout << "Zakonczono program." << endl;
        return 1;
    }

    if (!pobierzDlugosc("Podaj dlugosc drugiej podstawy (b): ", b)) {
        cout << "Zakonczono program." << endl;
        return 1;
    }

    if (!pobierzDlugosc("Podaj wysokosc (h): ", h)) {
        cout << "Zakonczono program." << endl;
        return 1;
    }

    double pole = (a + b) * h / 2;

    cout << "Pole trapezu wynosi: " << pole << endl;

    return 0;
}

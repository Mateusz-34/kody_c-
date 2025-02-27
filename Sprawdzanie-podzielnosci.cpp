#include <iostream>
using namespace std;

int main() {
    int pin;
    cout << "Podaj PIN: ";
    cin >> pin;

    int liczba;
    cout << "Podaj liczbe calkowita: ";
    cin >> liczba;

    if (pin == 1234) {
        if (liczba % 2 == 0) {
            cout << "Liczba jest podzielna przez dwa." << endl;
        } else {
            cout << "Liczba nie jest podzielna przez dwa." << endl;
        }
    } else {
        if (liczba % 5 == 0) {
            cout << "Liczba jest podzielna przez piec." << endl;
        } else {
            cout << "Liczba nie jest podzielna przez piec." << endl;
        }
    }

    return 0;
}

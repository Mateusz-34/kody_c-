#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x, y, wynik;

    do {
        cout << "Podaj x: ";
        cin >> x;
        cout << "Podaj y: ";
        cin >> y;

        if (x == 0 && y == 0) {
            cout << "Niepoprawne dane! x i y nie moga być jednocześnie równe 0." << endl;
        }
    } while (x == 0 && y == 0);

    wynik = pow(x, y);
    cout << "Wynik (pow()): " << wynik << endl;

    wynik = 1.0;
    for (int i = 0; i < abs(y); i++) {
        wynik *= x;
    }

    if (y < 0) {
        wynik = 1.0 / wynik;
    }

    cout << "Wynik (iteracyjnie): " << wynik << endl;

    return 0;
}
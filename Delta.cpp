#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    double delta;

    cout << "Podaj wspolczynniki a, b i c: ";
    cin >> a >> b >> c;

    delta = b * b - 4 * a * c;

    if (delta > 0) {
        double x1 = (-b + sqrt(delta)) / (2 * a);
        double x2 = (-b - sqrt(delta)) / (2 * a);
        
        cout << "Istnieja 2 miejsca zerowe: x1 = " << x1 << " i x2 = " << x2 << endl;
        
    } else if (delta == 0) {
        double x0 = -b / (2 * a);
        cout << "Istnieje 1 miejsce zerowe: x0 = " << x0 << endl;
        
    } else {
        cout << "Brak miejsc zerowych" << endl;
    }

    return 0;
}
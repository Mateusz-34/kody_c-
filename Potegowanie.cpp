#include <iostream>
#include <cmath>
using namespace std;
 
int main() {

    double x, y;

    do {
        cout << "Podaj x (x > 0): ";
        cin >> x;
    } while (x <= 0);
    do {
        cout << "Podaj y (y >= 0): ";
        cin >> y;
    } while (y < 0);
    double wynik = pow(x, y);
    
    cout << "Wynik obliczenia " << x << "^" << y << " to " << wynik << endl;

    return 0;
}
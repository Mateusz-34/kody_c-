#include <iostream>
using namespace std;

int main() {
    double a, b, h;

    cout << "Podaj długość pierwszej podstawy trapezu (a): ";
    cin >> a;

    cout << "Podaj długość drugiej podstawy trapezu (b): ";
    cin >> b;

    cout << "Podaj wysokość trapezu (h): ";
    cin >> h;

    double pole = 0.5 * (a + b) * h;

    cout << "Pole powierzchni trapezu wynosi: " << pole << endl;

    return 0;
}
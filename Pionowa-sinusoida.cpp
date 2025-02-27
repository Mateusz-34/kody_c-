#include <iostream>
#include <cmath>

using namespace std;

const int WYSOKOSC = 20;
const int SZEROKOSC = 40;

int main() {
    for (int x = 0; x <= SZEROKOSC; ++x) {
        double kat = (x * 360.0) / SZEROKOSC;
        double wartosc_sin = sin(kat * M_PI / 180.0);
        int pozycja = static_cast<int>((wartosc_sin + 1) * (WYSOKOSC / 2));
        
        for (int y = 0; y < WYSOKOSC; ++y) {
            if (y == pozycja) {
                cout << "*";
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

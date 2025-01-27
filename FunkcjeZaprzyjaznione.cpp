#include <iostream>
using namespace std;

class Punkt {
public:
    int x, y;
};

class Prostokat {
public:
    int x, y, szerokosc, wysokosc;

    Prostokat(int a, int b, int szer, int wys) {
        x = a;
        y = b;
        szerokosc = szer;
        wysokosc = wys;
    }

    friend bool czyPunktNalezy(const Punkt& p, const Prostokat& r);
};

bool czyPunktNalezy(const Punkt& p, const Prostokat& r) {
    return p.x >= r.x && p.x <= r.x + r.szerokosc && p.y >= r.y && p.y <= r.y + r.wysokosc;
}

int main() {
    int x, y, szerokosc, wysokosc;

    cout << "Podaj wspolrzedne punktu (x, y): ";
    cin >> x >> y;
    
    Punkt p = {x, y};

    cout << "Podaj szerokosc i wysokosc prostokata: ";
    cin >> szerokosc >> wysokosc;

    Prostokat r(x, y, szerokosc, wysokosc);


    if (czyPunktNalezy(p, r)) {
        cout << "Punkt (" << p.x << ", " << p.y << ") nalezy." << endl;
    } else {
        cout << "Punkt (" << p.x << ", " << p.y << ") nie nalezy." << endl;
    }

    return 0;
}
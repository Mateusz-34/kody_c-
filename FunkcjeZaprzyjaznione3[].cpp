#include <iostream>
using namespace std;

class Punkt {
public:
    int x, y, z;
    Punkt(int a, int b, int c) : x(a), y(b), z(c) {}
};

class Prostokat {
public:
    int x, y, z, szerokosc, wysokosc;

    Prostokat(int a, int b, int c, int szer, int wys) {
        x = a;
        y = b;
        z = c;
        szerokosc = szer;
        wysokosc = wys;
    }

    friend bool czyPunktNalezy(const Punkt& p, const Prostokat& r);
};

bool czyPunktNalezy(const Punkt& p, const Prostokat& r) {
    return p.x >= r.x && p.x <= r.x + r.szerokosc && p.y >= r.y && p.y <= r.y + r.wysokosc && p.z == r.z;
}

int main() {
    int x, y, z, szerokosc, wysokosc;

    cout << "Podaj wspolrzedne punktu (x, y, z): ";
    cin >> x >> y >> z;
    
    Punkt p(x, y, z);

    cout << "Podaj szerokosc i wysokosc prostokata: ";
    cin >> szerokosc >> wysokosc;

    Prostokat r(x, y, z, szerokosc, wysokosc);

    if (czyPunktNalezy(p, r)) {
        cout << "Punkt (" << p.x << ", " << p.y << ", " << p.z << ") nalezy." << endl;
    } else {
        cout << "Punkt (" << p.x << ", " << p.y << ", " << p.z << ") nie nalezy." << endl;
    }

    return 0;
}
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(nullptr));

    int a[8];
    double b[5];
    char c[10];
    bool d[10];

    for (int i = 0; i < 8; i++) {
        a[i] = rand() % 100;
    }

    for (int i = 0; i < 5; i++) {
        b[i] = (rand() / static_cast<double>(RAND_MAX)) * 100.0;
    }

    for (int i = 0; i < 10; i++) {
        c[i] = 'A' + rand() % 26;
        d[i] = rand() % 2 == 1;
    }

    cout << "Tablica a[] w normalnej kolejnosci:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Tablica b[] w kolejnosci odwrotnej:" << endl;
    for (int i = 4; i >= 0; i--) {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Wybrane elementy tablicy c[]:" << endl;
    for (int i = 0; i < 10; i++) {
        if (d[i]) {
            cout << c[i] << " ";
        }
    }
    cout << endl;

    return 0;
}

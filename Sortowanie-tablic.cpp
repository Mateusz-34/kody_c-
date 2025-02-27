#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    srand(time(nullptr));

    int tablica[10];
    for (int i = 0; i < 10; ++i) {
        tablica[i] = rand() % 41 - 20;
    }

    cout << "Zawartosc tablicy przed sortowaniem:\n";
    for (int i = 0; i < 10; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    sort(tablica, tablica + 10);

    cout << "Zawartosc tablicy posortowanej rosnaco:\n";
    for (int i = 0; i < 10; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    sort(tablica, tablica + 10, greater<int>());

    cout << "Zawartosc tablicy posortowanej malejaco:\n";
    for (int i = 0; i < 10; ++i) {
        cout << tablica[i] << " ";
    }
    cout << endl;

    return 0;
}

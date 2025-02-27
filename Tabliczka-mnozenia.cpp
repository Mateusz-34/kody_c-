#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    int rozmiar = 10;

    cout << "Tabliczka mnozenia " << rozmiar << "x" << rozmiar << ":" << endl;

    cout << "   ";
    for (int i = 1; i <= rozmiar; ++i) {
        cout << setw(4) << i;
    }
    cout << endl;

    cout << "   ";
    for (int i = 1; i <= rozmiar; ++i) {
        cout << "----";
    }
    cout << endl;

    for (int i = 1; i <= rozmiar; ++i) {
        cout << setw(2) << i << " |";
        for (int j = 1; j <= rozmiar; ++j) {
            cout << setw(4) << i * j;
        }
        cout << endl;
    }

    return 0;
}
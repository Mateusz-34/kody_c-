#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    const int n = 10;
    int a[n];
    int* b[n];

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < n; ++i) {
        a[i] = rand() % 41 - 20;
    }

    for (int i = 0; i < n; ++i) {
        b[i] = &a[i];
    }

    cout << "Zawartosc tablicy b przed sortowaniem:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *b[i] << " ";
    }
    cout << endl;

    sort(b, b + n, [](const int* lhs, const int* rhs) {
        return *lhs < *rhs;
    });

    cout << "Zawartosc tablicy b po sortowaniu:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << *b[i] << " ";
    }
    cout << endl;

    return 0;
}

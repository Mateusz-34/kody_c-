#include <iostream>
using namespace std;

int main() {
    int wysokosc;

    cout << "Podaj wysokosc trojkata: ";
    cin >> wysokosc;

    for (int i = 1; i <= wysokosc; ++i) {
        for (int j = 1; j <= wysokosc - i; ++j) {
            cout << " ";
        }
        
        for (int k = 1; k <= 2 * i - 1; ++k) {
            cout << "*";
        }
        
        cout << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;
#include <cmath>

bool czyLiczbaPierwsza(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    char kontynuuj;
    
    do {
        int liczba;
        
        cout << "Podaj liczbe calkowita: ";
        cin >> liczba;

        cout << "Dzielniki liczby " << liczba << " to:";
        for (int i = 1; i <= liczba; ++i) {
            if (liczba % i == 0) {
                cout << " " << i;
            }
        }
        cout << endl;

        if (czyLiczbaPierwsza(liczba)) {
            cout << "Podana liczba jest liczba pierwsza." << endl;
        } else {
            cout << "Podana liczba nie jest liczba pierwsza." << endl;
        }

        cout << "Czy chcesz kontynuowac (t/n)? ";
        cin >> kontynuuj;
        cout << endl;

    } while (kontynuuj == 't' || kontynuuj == 'T');

    return 0;
}
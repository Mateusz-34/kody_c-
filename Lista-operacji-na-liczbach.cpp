#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Podaj liczbe calkowita: ";
    cin >> n;

    if (n <= 0) {
        cout << "Podana liczba musi byc wieksza od zera!" << endl;
        return 1;
    }

    cout << "Liczby od 1 do " << n << " to:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << i;
        if (i < n) cout << ", ";
    }
    cout << endl;

    cout << "Liczby od " << n << " do 1 w odwrotnej kolejnosci to:" << endl;
    for (int i = n; i >= 1; --i) {
        cout << i;
        if (i > 1) cout << ", ";
    }
    cout << endl;

    cout << "Liczby nieparzyste mniejsze od " << n << " to:" << endl;
    bool pierwsza = true;
    for (int i = 1; i < n; i += 2) {
        if (!pierwsza) cout << ", ";
        cout << i;
        pierwsza = false;
    }
    cout << endl;

    cout << "Wielokrotnosci liczby 5 mniejsze od " << n << " to:" << endl;
    pierwsza = true;
    for (int i = 5; i < n; i += 5) {
        if (!pierwsza) cout << ", ";
        cout << i;
        pierwsza = false;
    }
    cout << endl;

    cout << "Male litery alfabetu od 'a' do 'z' to:" << endl;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        cout << letter << " ";
    }
    cout << endl;

    return 0;
}
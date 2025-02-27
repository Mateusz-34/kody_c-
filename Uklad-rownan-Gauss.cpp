#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void wyswietlMacierz(const vector<vector<double>>& macierz) {
    int n = macierz.size();
    cout << fixed << setprecision(4); // Formatowanie liczb
    for (const auto& wiersz : macierz) {
        for (double wartosc : wiersz) {
            cout << setw(10) << wartosc << " ";  // Lepsze wyrównanie kolumn
        }
        cout << endl;
    }
}

void eliminacjaGaussa(vector<vector<double>>& macierz) {
    int n = macierz.size();

    for (int k = 0; k < n; ++k) {
        int maxIndeks = k;
        for (int i = k + 1; i < n; ++i) {
            if (abs(macierz[i][k]) > abs(macierz[maxIndeks][k])) {
                maxIndeks = i;
            }
        }

        swap(macierz[k], macierz[maxIndeks]);  // Zamiana wierszy zamiast pętli
        
        if (macierz[k][k] == 0) {  // Obsługa dzielenia przez zero
            cout << "Blad: macierz osobliwa, brak jednoznacznego rozwiazania." << endl;
            return;
        }

        for (int i = k + 1; i < n; ++i) {
            double f = macierz[i][k] / macierz[k][k];
            for (int j = k; j < n + 1; ++j) {
                macierz[i][j] -= f * macierz[k][j];
            }
        }
    }

    vector<double> rozwiazania(n);
    for (int i = n - 1; i >= 0; --i) {
        rozwiazania[i] = macierz[i][n];
        for (int j = i + 1; j < n; ++j) {
            rozwiazania[i] -= macierz[i][j] * rozwiazania[j];
        }
        rozwiazania[i] /= macierz[i][i];
    }

    cout << "\nRozwiazania układu równań:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << rozwiazania[i] << endl;
    }
}

int main() {
    int n;

    cout << "Podaj liczbe niewiadomych: ";
    cin >> n;

    vector<vector<double>> macierz(n, vector<double>(n + 1));

    cout << "Podaj wspolczynniki i wyrazy wolne:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n + 1; ++j) {
            cout << "A[" << i + 1 << "][" << j + 1 << "] = ";
            cin >> macierz[i][j];
        }
    }

    cout << "\nPoczatkowa macierz:" << endl;
    wyswietlMacierz(macierz);

    eliminacjaGaussa(macierz);

    return 0;
}

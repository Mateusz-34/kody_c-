#include <iostream>
#include <algorithm>

using namespace std;

void wyswietlTablice(int** tablica, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            cout << tablica[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

void sortujWiersze(int** tablica, int wiersze, int kolumny) {
    for (int i = 0; i < wiersze; ++i) {
        sort(tablica[i], tablica[i] + kolumny);
    }
}

void sortujKolumny(int** tablica, int wiersze, int kolumny) {
    for (int j = 0; j < kolumny; ++j) {
        for (int i = 0; i < wiersze - 1; ++i) {
            for (int k = i + 1; k < wiersze; ++k) {
                if (tablica[i][j] > tablica[k][j]) {
                    swap(tablica[i][j], tablica[k][j]);
                }
            }
        }
    }
}

void sortujCalaTablice(int** tablica, int wiersze, int kolumny) {
    int* wszystkieWartosci = new int[wiersze * kolumny];
    int index = 0;

    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            wszystkieWartosci[index++] = tablica[i][j];
        }
    }

    sort(wszystkieWartosci, wszystkieWartosci + wiersze * kolumny);

    index = 0;
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            tablica[i][j] = wszystkieWartosci[index++];
        }
    }

    delete[] wszystkieWartosci;
}

int main() {
    int wiersze, kolumny;

    cout << "Podaj liczbe wierszy: ";
    cin >> wiersze;
    cout << "Podaj liczbe kolumn: ";
    cin >> kolumny;

    if (wiersze <= 0 || kolumny <= 0) {
        cout << "Bledne wymiary tablicy!" << endl;
        return 1;
    }

    int** tablica = new int*[wiersze];
    for (int i = 0; i < wiersze; ++i) {
        tablica[i] = new int[kolumny];
    }

    srand(time(0));
    for (int i = 0; i < wiersze; ++i) {
        for (int j = 0; j < kolumny; ++j) {
            tablica[i][j] = rand() % 100;
        }
    }

    cout << "\nPoczatkowa tablica:\n";
    wyswietlTablice(tablica, wiersze, kolumny);

    sortujWiersze(tablica, wiersze, kolumny);
    cout << "Tablica posortowana wedlug wierszy:\n";
    wyswietlTablice(tablica, wiersze, kolumny);

    sortujKolumny(tablica, wiersze, kolumny);
    cout << "Tablica posortowana wedlug kolumn:\n";
    wyswietlTablice(tablica, wiersze, kolumny);

    sortujCalaTablice(tablica, wiersze, kolumny);
    cout << "Tablica posortowana wedlug wszystkich wartosci:\n";
    wyswietlTablice(tablica, wiersze, kolumny);

    for (int i = 0; i < wiersze; ++i) {
        delete[] tablica[i];
    }
    delete[] tablica;

    return 0;
}
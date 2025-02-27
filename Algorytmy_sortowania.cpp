#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int rozmiar = 12;

void wypelnijTab(int tablica[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; ++i) tablica[i] = rand() % 100;
}

void drukujTab(int tablica[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << tablica[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << '\n';
}

void sortowanie_babelkowe(int tablica[], int n) {
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (tablica[j] > tablica[j + 1]) {
                int temp = tablica[j];
                tablica[j] = tablica[j + 1];
                tablica[j + 1] = temp;
            }
}

void sortowanie_przez_wstrzasanie(int tablica[], int n) {
    bool zamieniono = true;
    int start = 0, koniec = n - 1;

    while (zamieniono) {
        zamieniono = false;

        for (int i = start; i < koniec; ++i) {
            if (tablica[i] > tablica[i + 1]) {
                int temp = tablica[i];
                tablica[i] = tablica[i + 1];
                tablica[i + 1] = temp;
                zamieniono = true;
            }
        }

        if (!zamieniono) break;

        zamieniono = false;
        --koniec;

        for (int i = koniec - 1; i >= start; --i) {
            if (tablica[i] > tablica[i + 1]) {
                int temp = tablica[i];
                tablica[i] = tablica[i + 1];
                tablica[i + 1] = temp;
                zamieniono = true;
            }
        }
    }
}

void scalanie(int tablica[], int poczatek, int srodek, int koniec) {
    int rozmiar1 = srodek - poczatek + 1;
    int rozmiar2 = koniec - srodek;

    int lewa[rozmiar1];
    int prawa[rozmiar2];

    for (int i = 0; i < rozmiar1; ++i) lewa[i] = tablica[poczatek + i];
    for (int j = 0; j < rozmiar2; ++j) prawa[j] = tablica[srodek + 1 + j];

    int i = 0, j = 0, k = poczatek;

    while (i < rozmiar1 && j < rozmiar2) {
        tablica[k++] = (lewa[i] <= prawa[j]) ? lewa[i++] : prawa[j++];
    }

    while (i < rozmiar1) tablica[k++] = lewa[i++];
    while (j < rozmiar2) tablica[k++] = prawa[j++];
}

void sortowanie_przez_scalanie(int tablica[], int poczatek, int koniec) {
    if (poczatek < koniec) {
        int srodek = poczatek + (koniec - poczatek) / 2;

        sortowanie_przez_scalanie(tablica, poczatek, srodek);
        sortowanie_przez_scalanie(tablica, srodek + 1, koniec);

        scalanie(tablica, poczatek, srodek, koniec);
    }
}

void sortowanie_szybkie(int tablica[], int poczatek, int koniec) {
    if (poczatek < koniec) {
        int pivot = tablica[koniec];
        int i = poczatek - 1;

        for (int j = poczatek; j <= koniec - 1; ++j) {
            if (tablica[j] < pivot) {
                ++i;
                swap(tablica[i], tablica[j]);
            }
        }

        swap(tablica[i + 1], tablica[koniec]);

        sortowanie_szybkie(tablica, poczatek, i);
        sortowanie_szybkie(tablica, i + 1, koniec);
    }
}

void sortowanie_przez_wstawianie(int tablica[], int n) {
    for (int i = 1; i < n; ++i) {
        int klucz = tablica[i];
        int j = i - 1;

        while (j >= 0 && tablica[j] > klucz) {
            tablica[j + 1] = tablica[j];
            --j;
        }

        tablica[j + 1] = klucz;
    }
}

int main() {
    int tablica[rozmiar];
    int n = rozmiar;

    wypelnijTab(tablica, n);

    cout << "Przed sortowaniem:\n";
    drukujTab(tablica, n);

    int tablica_copy[rozmiar];

    copy(begin(tablica), end(tablica), begin(tablica_copy));
    sortowanie_babelkowe(tablica_copy, n);
    cout << "Po sortowaniu bąbelkowym:\n";
    drukujTab(tablica_copy, n);

    copy(begin(tablica), end(tablica), begin(tablica_copy));
    sortowanie_przez_wstrzasanie(tablica_copy, n);
    cout << "Po sortowaniu przez wstrząsanie:\n";
    drukujTab(tablica_copy, n);

    copy(begin(tablica), end(tablica), begin(tablica_copy));
    sortowanie_przez_scalanie(tablica_copy, 0, n - 1);
    cout << "Po sortowaniu przez scalanie:\n";
    drukujTab(tablica_copy, n);

    copy(begin(tablica), end(tablica), begin(tablica_copy));
    sortowanie_szybkie(tablica_copy, 0, n - 1);
    cout << "Po sortowaniu szybkim:\n";
    drukujTab(tablica_copy, n);

    copy(begin(tablica), end(tablica), begin(tablica_copy));
    sortowanie_przez_wstawianie(tablica_copy, n);
    cout << "Po sortowaniu przez wstawianie:\n";
    drukujTab(tablica_copy, n);

    return 0;
}
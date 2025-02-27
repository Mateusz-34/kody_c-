#include <iostream>
#include <cmath>

using namespace std;

int wyszukiwanie_liniowe(int *tablica, int rozmiar, int klucz) {
    for (int i = 0; i < rozmiar; i++) {
        if (tablica[i] == klucz) {
            return i;
        }
    }
    return -1;
}

int wyszukiwanie_liniowe_z_wartownikiem(int *tablica, int rozmiar, int klucz) {
    tablica[rozmiar] = klucz;
    int i = 0;
    while (tablica[i] != klucz) {
        i++;
    }
    return (i < rozmiar) ? i : -1;
}

int wyszukiwanie_skokowe(int *tablica, int rozmiar, int klucz) {
    int krok = sqrt(rozmiar);
    int poprzedni = 0;
    while (tablica[min(krok, rozmiar) - 1] < klucz) {
        poprzedni = krok;
        krok += sqrt(rozmiar);
        if (poprzedni >= rozmiar) {
            return -1;
        }
    }
    for (int i = poprzedni; i < min(krok, rozmiar); i++) {
        if (tablica[i] == klucz) {
            return i;
        }
    }
    return -1;
}

int wyszukiwanie_binarne(int *tablica, int rozmiar, int klucz) {
    int lewy = 0, prawy = rozmiar - 1;
    while (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;
        if (tablica[srodek] == klucz) {
            return srodek;
        } else if (tablica[srodek] < klucz) {
            lewy = srodek + 1;
        } else {
            prawy = srodek - 1;
        }
    }
    return -1;
}

int wyszukiwanie_interpolacyjne(int *tablica, int rozmiar, int klucz) {
    int lewy = 0, prawy = rozmiar - 1;
    while (lewy <= prawy && klucz >= tablica[lewy] && klucz <= tablica[prawy]) {
        int pozycja = lewy + ((klucz - tablica[lewy]) * (prawy - lewy)) / (tablica[prawy] - tablica[lewy]);
        if (pozycja < 0 || pozycja >= rozmiar) {
            return -1;
        }
        if (tablica[pozycja] == klucz) {
            return pozycja;
        } else if (tablica[pozycja] < klucz) {
            lewy = pozycja + 1;
        } else {
            prawy = pozycja - 1;
        }
    }
    return -1;
}

void wyswietl_wynik_wyszukiwania(const char *algorytm, int wynik) {
    if (wynik != -1) {
        cout << algorytm << ": Znaleziono element na indeksie " << wynik << endl;
    } else {
        cout << algorytm << ": Element nie został znaleziony" << endl;
    }
}

int main() {
    int tablica[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);
    int klucz = 7;

    wyswietl_wynik_wyszukiwania("Wyszukiwanie liniowe", wyszukiwanie_liniowe(tablica, rozmiar, klucz));
    wyswietl_wynik_wyszukiwania("Wyszukiwanie liniowe z wartownikiem", wyszukiwanie_liniowe_z_wartownikiem(tablica, rozmiar, klucz));
    wyswietl_wynik_wyszukiwania("Wyszukiwanie skokowe", wyszukiwanie_skokowe(tablica, rozmiar, klucz));
    wyswietl_wynik_wyszukiwania("Wyszukiwanie binarne", wyszukiwanie_binarne(tablica, rozmiar, klucz));
    wyswietl_wynik_wyszukiwania("Wyszukiwanie interpolacyjne", wyszukiwanie_interpolacyjne(tablica, rozmiar, klucz));

    return 0;
}

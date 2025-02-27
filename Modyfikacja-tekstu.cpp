#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
    const int max_length = 80;
    char tekst[max_length];

    cout << "Wprowadz linijke tekstu (do " << max_length - 1 << " znakow): ";
    cin.getline(tekst, max_length);

    int liczba_spacji = 0;

    for (int i = 0; i < strlen(tekst); ++i) {
        if (tekst[i] == ' ') {
            liczba_spacji++;
        }
    }

    for (int i = 0; i < strlen(tekst); ++i) {
        if (islower(tekst[i])) {
            tekst[i] = toupper(tekst[i]);
        }
    }

    cout << "Tekst po zamianie na wielkie litery:" << endl;
    cout << tekst << endl;

    cout << "Liczba spacji w tekście: " << liczba_spacji << endl;

    return 0;
}

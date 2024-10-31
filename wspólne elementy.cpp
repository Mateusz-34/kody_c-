#include <iostream>
using namespace std;
 
int main() {
    int rozmiar1, rozmiar2;
 
    cout << "Podaj rozmiar pierwszej tablicy: ";
    cin >> rozmiar1;
    cout << "Podaj rozmiar drugiej tablicy: ";
    cin >> rozmiar2;
 
    char* tab1 = new char[rozmiar1];
    char* tab2 = new char[rozmiar2];
 
    cout << "Podaj elementy pierwszej tablicy:" << endl;
    for (int i = 0; i < rozmiar1; i++) {
        cin >> tab1[i];
    }
 
    cout << "Podaj elementy drugiej tablicy:" << endl;
    for (int i = 0; i < rozmiar2; i++) {
        cin >> tab2[i];
    }
 
    cout << "Wspólne elementy:" << endl;
    for (int i = 0; i < rozmiar1; i++) {
        for (int j = 0; j < rozmiar2; j++) {
            if (tab1[i] == tab2[j]) {
                cout << tab1[i] << " ";
                break;
            }
        }
    }
 
    delete[] tab1;
    delete[] tab2;
 
    return 0;
}
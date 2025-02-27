#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace chrono;

int potegaDwojki(int wykladnik) {
    return 1 << wykladnik; 
}

int main() {
    int liczbaKrazkow;
    cout << "Podaj liczbe krazkow: ";
    cin >> liczbaKrazkow;

    vector<int> pozycjaKrazka(liczbaKrazkow, 0);

    int liczbaRuchow = (1 << liczbaKrazkow) - 1;
    int wykonaneRuchy = 0;

    auto start = high_resolution_clock::now();

    for (int j = 1; j <= liczbaRuchow; j++) {
        int krazek = 0;
        while (true) {
            int potega = potegaDwojki(krazek);
            int ruch = potega * 2;

            if (((j - potega) % ruch) == 0) {
                if ((liczbaKrazkow + 1) % 2) {
                    pozycjaKrazka[krazek] += 2;
                } else {
                    pozycjaKrazka[krazek] += 1;
                }
                pozycjaKrazka[krazek] %= 3;
                cout << "Przeniesienie krazka " << krazek + 1 << " na patyk " << pozycjaKrazka[krazek] + 1 << endl;
                wykonaneRuchy++;
                break;
            }
            krazek++;
        }
    }

    auto stop = high_resolution_clock::now();
    auto czasWykonania = duration_cast<microseconds>(stop - start);

    cout << "Liczba ruchow: " << wykonaneRuchy << endl;
    cout << "Czas wykonania: " << czasWykonania.count() << " mikrosekund" << endl;

    return 0;
}

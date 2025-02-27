#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    double krok;

    cout << "Podaj krok (co ile stopni): ";
    cin >> krok;

    if (krok <= 0 || krok > 90) {
        cout << "Niepoprawny krok. Wprowadz wartosc z przedzialu (0, 90]." << endl;
        return 1;
    }

    cout << fixed << setprecision(4);
    cout << "Kat (stopnie)\tSin\t\tCos\t\tTan\t\tCot" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (double stopnie = 0; stopnie <= 90; stopnie += krok) {
        double radiany = stopnie * M_PI / 180.0;
        double sin_val = sin(radiany);
        double cos_val = cos(radiany);

        cout << setw(10) << stopnie << "\t" << setw(8) << sin_val << "\t" << setw(8) << cos_val << "\t";

        if (cos_val == 0) {
            cout << "   ---   \t   ---" << endl;
        } else {
            double tan_val = tan(radiany);
            double cot_val = 1.0 / tan_val;
            cout << setw(8) << tan_val << "\t" << setw(8) << cot_val << endl;
        }
    }

    return 0;
}

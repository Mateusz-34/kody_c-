#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    char operation;

    cout << "Podaj pierwsza liczbe: ";
    cin >> num1;

    cout << "Podaj druga liczbe: ";
    cin >> num2;

    cout << "Wybierz dzialanie (+, -, *, /): ";
    cin >> operation;

    double result;
    
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Blad: Dzielenie przez zero!" << endl;
                return 1;
            }
            break;
        default:
            cout << "Blad: Nieprawidlowy operator." << endl;
            return 1;
    }

    cout << "Wynik: " << result << endl;

    return 0;
}

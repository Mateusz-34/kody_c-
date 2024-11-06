#include <iostream>

using namespace std;

int main() {
    char operation;
    double num1, num2;

    cout << "Prosty kalkulator\n";
    cout << "Podaj operację (+, -, *, /): ";
    cin >> operation;
    cout << "Podaj dwie liczby: ";
    cin >> num1 >> num2;

    switch(operation) {
        case '+':
            cout << "Wynik: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Wynik: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Wynik: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0) {
                cout << "Wynik: " << num1 / num2 << endl;
            } else {
                cout << "Błąd: Dzielenie przez zero!" << endl;
            }
            break;
        default:
            cout << "Nieprawidłowa operacja!" << endl;
            break;
    }

    return 0;
}
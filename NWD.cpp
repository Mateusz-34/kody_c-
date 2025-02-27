#include <iostream>
using namespace std;
 

int nwd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

 

int main() {
    int num1, num2;

    cout << "Podaj dwie liczby całkowite: ";
    cin >> num1 >> num2;


    int result = nwd(num1, num2);
    cout << "Największy wspólny dzielnik (NWD) liczby " << num1 << " i " << num2 << " wynosi: " << result << endl;

    return 0;
}
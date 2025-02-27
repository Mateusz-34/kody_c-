#include <iostream>
using namespace std;

int main() {
    
    double celsius;
    double kelvin;
    double fahrenheit;

    cout << "Celsius\tKelvin\tFahrenheit" << endl;

    for (celsius = -120; celsius <= 120; celsius += 10) {
        kelvin = celsius + 273.15;
        fahrenheit = (celsius * 9/5) + 32;
        cout << celsius << "\t" << kelvin << "\t" << fahrenheit << endl;
    }

    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    double r;  
    double pole;

    cout << "Podaj promień koła: ";
    cin >> r;

    pole = M_PI * pow(r, 2);

    cout << "Pole koła o promieniu " << r << " wynosi: " << pole << endl;

    return 0;
}
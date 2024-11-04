#include <iostream>
#include <cmath>
using namespace std;
 
double taylor_cos(double x, int terms) {
   double sum = 1.0;
   double term = 1.0;
   for (int n = 1; n < terms; ++n) {
       term *= -x * x / (2 * n * (2 * n - 1));
       sum += term;
   }
   return sum;
}
 
int main() {
   double x;
   int terms;
   
   cout << "Podaj wartość x (w radianach): ";
   cin >> x;
   
   cout << "Podaj liczbę wyrazów szeregu: ";
   cin >> terms;
   
   double cos_approx = taylor_cos(x, terms);
   cout << "Przybliżona wartość cos(" << x << ") = " << cos_approx << endl;
   cout << "Wartość z biblioteki cmath cos(" << x << ") = " << cos(x) << endl;
   return 0;
}
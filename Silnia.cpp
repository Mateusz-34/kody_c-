#include <iostream>
using namespace std;

unsigned long long iteracyjnaSilnia (int n) {
  if (n < 0){
    return 0;
  }

unsigned long long wynik = 1;
  for (int i = 1; i <= n; i++){
    wynik *= i;
  }
  return wynik;
}

int main () {
    
  int liczba;

  cout << "Podaj liczbe calkowita: ";
  cin >> liczba;

  unsigned long long wynik = iteracyjnaSilnia (liczba);
  cout << "Silnia z " << liczba << " to " << wynik << endl;

  return 0;
}
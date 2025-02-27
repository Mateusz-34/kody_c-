#include <iostream>
#include <algorithm>
using namespace std;


int main () {

  double liczba1, liczba2, liczba3;

  cout << "Podaj trzy liczby: ";
  cin >> liczba1 >> liczba2 >> liczba3;

  double srednia = (liczba1 + liczba2 + liczba3) / 3.0;
  cout << "Srednia z podanych liczb: " << srednia << endl;

  double liczby[3] = { liczba1, liczba2, liczba3 };
  sort (liczby, liczby + 3, greater < double >());
  cout << "Liczby posortowane malejaco: " << liczby[0] << ", " << liczby[1] << ", " << liczby[2] << endl;
  
  sort (liczby, liczby + 3);
  cout << "Liczby posortowane rosnaco: " << liczby[0] << ", " << liczby[1] << ", " << liczby[2] << endl;

  return 0;
}
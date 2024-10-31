#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
int main() {
    srand(time(0)); 
    vector<int> numbers;
    int n = 10;
 
    for (int i = 0; i < n; ++i) {
        numbers.push_back(rand() % 100); 
    }
 
    sort(numbers.begin(), numbers.end());
 
    cout << "Posortowane liczby rosnąco: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
 
    sort(numbers.begin(), numbers.end(), greater<int>());
 
    cout << "Posortowane liczby malejąco: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
 
    return 0;
}
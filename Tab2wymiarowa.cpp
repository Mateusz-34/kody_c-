#include <iostream>
#include <cstdlib>
#include <ctime>
 
using namespace std;
 
class Array2D {
private:
    int** array;
    int rows;
    int cols;
 
public:
    Array2D(int r, int c) : rows(r), cols(c) {
        array = new int*[rows];
        for (int i = 0; i < rows; i++) {
            array[i] = new int[cols];
        }
 
        srand(time(0));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                array[i][j] = rand() % 100;
            }
        }
    }
 
    void printArray() {
        cout << "Wszystkie liczby w tablicy: " << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
    }
 
    void printEvenNumbers() {
        cout << "Parzyste liczby w tablicy: " << endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (array[i][j] % 2 == 0) {
                    cout << array[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
 
    void freeMemory() {
        for (int i = 0; i < rows; i++) {
            delete[] array[i];
        }
        delete[] array;
    }
};
 
int main() {
    int rows = 5;
    int cols = 5;
 
    Array2D arr(rows, cols);
    arr.printArray();
    arr.printEvenNumbers();
    arr.freeMemory();
 
    return 0;
}
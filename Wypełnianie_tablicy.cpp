#include <iostream>
using namespace std;

int* fillArray(int size) {
    int* array = new int[size];
    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
    }
    return array;
}

int main() {
    int size = 10;
    int* myArray = fillArray(size);

    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }

    delete[] myArray;

    return 0;
}
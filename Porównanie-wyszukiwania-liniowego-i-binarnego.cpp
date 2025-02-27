#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

unsigned long long int atime() {
    unsigned long long int cnt;
    __asm__ volatile (".byte 0x0f, 0x31" : "=A" (cnt));
    return cnt;
}

void genRandomArray(int *arr, int size, int range) {
    bool used[range] = {false};

    for(int i = 0; i < size; ++i) {
        int num;
        do {
            num = rand() % range;
        } while (used[num]);
        arr[i] = num;
        used[num] = true;
    }
}

int linearSearch(int *arr, int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binarySearch(int *arr, int size, int key) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    srand(time(nullptr));

    int size, range;
    cout << "Podaj rozmiar tablicy: ";
    cin >> size;
    cout << "Podaj zakres losowanych liczb: ";
    cin >> range;

    int *arr = new int[size];

    unsigned long long int end_linear = 0;
    unsigned long long int start_linear = 0;
    int key_linear = rand() % range;
    start_linear = atime();

    linearSearch(arr, size, key_linear);

    end_linear += (atime() - start_linear) / 1000;

    cout << "Czas wyszukiwania liniowego: " << end_linear << " mikrosekund" << endl;


    unsigned long long int end_binary = 0;
    unsigned long long int start_binary = 0;
    int key_binary = rand() % range; 
    start_binary = atime();

    binarySearch(arr, size, key_binary);

    end_binary += (atime() - start_binary) / 1000;

    cout << "Czas wyszukiwania binarnego: " << end_binary << " mikrosekund" << endl;

    delete[] arr;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CharArray2D {
private:
    vector<vector<char>> array;
    int rows;
    int cols;

public:
    CharArray2D(int r, int c) : rows(r), cols(c) {
        array.resize(rows, vector<char>(cols));
    }

    void fillArray() {
        cout << "Podaj znaki do tablicy (wierszami):" << endl;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cin >> array[i][j];
            }
        }
    }

    void sortArray() {
        vector<char> temp;
        for (const auto& row : array) {
            temp.insert(temp.end(), row.begin(), row.end());
        }

        sort(temp.begin(), temp.end());

        int index = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                array[i][j] = temp[index++];
            }
        }
    }

    void printArray() const {
        cout << "Posortowana tablica:" << endl;
        for (const auto& row : array) {
            for (char ch : row) {
                cout << ch << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int rows, cols;
    cout << "Podaj liczbę wierszy: ";
    cin >> rows;
    cout << "Podaj liczbę kolumn: ";
    cin >> cols;

    CharArray2D array(rows, cols);
    array.fillArray();
    array.sortArray();
    array.printArray();

    return 0;
}
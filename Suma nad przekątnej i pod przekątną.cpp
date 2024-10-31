#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    vector<vector<int>> matrix;
    int size;

public:
    Matrix(const vector<vector<int>>& mat) : matrix(mat), size(mat.size()) {}

    int sumAboveDiagonal() {
        int sum = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                sum += matrix[i][j];
            }
        }
        return sum;
    }

    int sumBelowDiagonal() {
        int sum = 0;
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Matrix matrix(mat);
    cout << "Sum above diagonal: " << matrix.sumAboveDiagonal() << endl;
    cout << "Sum below diagonal: " << matrix.sumBelowDiagonal() << endl;

    return 0;
}
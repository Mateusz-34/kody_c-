#include <iostream>
#include <vector>
using namespace std;
 
 
vector<vector<int>> transpose(const vector<vector<int>>& matrix) {
    size_t rows = matrix.size();  
    size_t cols = matrix[0].size();     
    vector<vector<int>> transposed(cols, vector<int>(rows));
 
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            transposed[j][i] = matrix[i][j];
        }
    }
 
    return transposed;
}
 
 
int main() {
 
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
 
 
    vector<vector<int>> transposedMatrix = transpose(matrix);
 
 
    for (const auto& row : transposedMatrix) {
        for (int val : row) {
            cout << val << ' ';
        }
        cout << '\n';
    }
 
    return 0;
}
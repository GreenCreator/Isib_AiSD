#include <iostream>
#include <vector>

std::vector<std::vector<int>> Transpose(const std::vector<std::vector<int>> &matrix) {
    std::vector<std::vector<int>> transposeMatrix(matrix[0].size(), std::vector<int>(matrix.size()));

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[0].size(); ++j) {
            transposeMatrix[j][i] = matrix[i][j];
        }
    }

    return transposeMatrix;
}

int main() {
}
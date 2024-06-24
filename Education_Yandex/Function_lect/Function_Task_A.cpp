#include <iostream>
#include <vector>

std::pair<size_t, size_t> MatrixArgMax(const std::vector<std::vector<int>> &matrix) {
    size_t x = 0;
    size_t y = 0;
    int max = matrix[0][0];

    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (matrix[i][j] > max) {
                x = i;
                y = j;
                max = matrix[i][j];
            }
        }
    }
    return std::pair<size_t, size_t>{x, y};

}

int main() {
    size_t n;
    size_t k;

    std::cin >> n >> k;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(k));

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < k; ++j) {
            int value;
            std::cin >> value;
            matrix[i][j] = value;
        }
    }

    auto pair = MatrixArgMax(matrix);

    std::cout << pair.first << " " << pair.second;

}
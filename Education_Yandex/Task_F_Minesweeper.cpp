#include <algorithm>
#include <vector>
#include "iostream"

int main() {
    int m;
    int n;
    int k;

    std::cin >> m >> n >> k;

    std::vector<std::vector<char>> field(m, std::vector<char>(n, '0'));
    std::vector<std::vector<int>> mineCoordinates;
    std::vector<std::pair<int, int>> directions = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0,  -1},
            {0,  1},
            {1,  -1},
            {1,  0},
            {1,  1}
    };

    for (int i = 0; i < k; ++i) {
        int x, y;
        std::cin >> x >> y;
        --x;
        --y;

        field[x][y] = '*';

        for (const auto &dir: directions) {
            int nx = x + dir.first;
            int ny = y + dir.second;
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && field[nx][ny] != '*') {
                field[nx][ny] = (field[nx][ny] == '0') ? '1' : field[nx][ny] + 1;
            }
        }
    }

    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
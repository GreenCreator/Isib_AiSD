#include <iostream>
#include <cstdint>

///Combinations

uint64_t ant_recursive(int i, int j) { // O(C^n
    if (i == 1 || j == 1) {
        return 1;
    }
    return ant_recursive(i, j - 1) + ant_recursive(i - 1, j);
}

uint64_t ant_dynamic(int i, int j) {
    uint64_t result;
    uint64_t ant[i][j];
    for (int row = 0; row < i; ++row) {
        for (int cell = 0; cell < j; ++cell) {
            ant[row][cell] = 0;
        }
    }
    for (int row = 0; row < i; ++row) {
        ant[row][0] = 1;
    }
    for (int cell = 0; cell < j; ++cell) {
        ant[0][cell] = 1;
    }
    for (int row = 1; row < i; ++row) {
        for (int cell = 1; cell < j; ++cell) {
            ant[row][cell] = ant[row][cell - 1] + ant[row - 1][cell];
        }
    }

    result = ant[i - 1][j - 1];
    return result;
}

int main() {
    uint64_t (*ant)(int, int);
    size_t vers = 0;
    std::cout << "Which version of Ant func use? (0 - recursive, 1 - dynamic)" << std::endl;
    std::cin >> vers;
    ant = vers == 0 ? ant_recursive : ant_dynamic;

    for (int i = 1; i <= 20; ++i) {
        for (int j = 1; j <= 10; ++j) {
            std::cout << ant(j, i) << "\t";
        }
        std::cout << std::endl;
    }
}
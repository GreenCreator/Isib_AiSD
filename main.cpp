#include <iostream>
#include <cmath>
#include <cstdint>


void ChangeStatus(bool *A, int value, int size) {
    for (int i = value * value; i <= size; i += value) {
        A[i] = false;
    }
}


int main() {
    size_t n;
    std::cin >> n;
    bool A[n + 1];
    for (int i = 2; i <= n; ++i) {
        A[i] = true;
    }

    for (int i = 2; i * i <= n; ++i) {

        if (A[i])
            ChangeStatus(A, i, n);
    }

    for (int i = 2; i <= n; ++i) {
        if (A[i])
            std::cout << i << std::endl;
    }
}
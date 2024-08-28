#include <cstdint>
#include <iostream>

void permutation(int16_t number, int16_t current, int16_t buffer[], bool used[]) {
    if (current == number) {
        for (int i = 0; i < number; ++i) {
            std::cout << buffer[i] << '\t';
        }
        std::cout << '\n';
        return;
    }

    for (int16_t variant = 0; variant < number; ++variant) {
        if (!used[variant]) {
            buffer[current] = variant;
            used[variant] = true;
            permutation(number, current + 1, buffer, used);
            used[variant] = false;
        }
    }
}


int main() {
    int n;
    std::cout << "Enter length to generate all permutations: ";
    std::cin >> n;
    std::cout << std::endl;
    if (n > 20) {
        std::cerr << "Too big";
        return 1;
    } else if (n <= 0) {
        std::cerr << "Number is negative";
        return 1;
    }

    int16_t buffer[n];
    bool used[n];
//    for (int i = 0; i < n; ++i) {
//        used[i] = false;
//    }

    permutation(n, 0, buffer, used);
}
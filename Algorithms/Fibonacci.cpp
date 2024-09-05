#include <iostream>
#include <cstdint>

uint64_t fib_recursive(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

uint64_t fib_dynamic(int n) {
    uint64_t result;
    uint64_t *fib = new uint64_t[n + 1];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    result = fib[n];
    delete[] fib;
    return result;
}

int main() {
    uint64_t (*fib)(int);
    size_t vers = 0;
    std::cout << "Which version of Fibonacci func use? (0 - recurvie, 1 - dynamic)" << std::endl;
    std::cin >> vers;
    fib = vers == 0 ? fib_recursive : fib_dynamic;

    for (int n = 0; n < 60; ++n) {
        std::cout << n << '\t' << fib(n) << std::endl;
    }
}
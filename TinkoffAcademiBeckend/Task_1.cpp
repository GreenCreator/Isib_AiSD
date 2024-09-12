#include <iostream>

int main() {
    size_t count;
    std::cin >> count;
    int socks;
    int sum = 0;

    while (count > 0) {
        std::cin >> socks;
        sum += socks;
        --count;
    }

    std::cout << (sum % 2 == 0 ? "YES" : "NO");
    return 0;
}
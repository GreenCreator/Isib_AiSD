#include <iostream>
#include <valarray>
#include <cstdint>

int reverse(int x) {
    uint64_t result = 0;
    while (x != 0) {
        result = result * 10 + x % 10;
        x /= 10;
    }
    return result;
}

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }
    int numb = reverse(x);
    return x == numb;
}

int main() {
    int x;
    std::cin >> x;

    std::cout << isPalindrome(x) << std::endl;
}

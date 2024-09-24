#include <iostream>
#include <valarray>

int reverse(int x) {
    int result = 0;
    while (x != 0) {
        result = result * 10 + x % 10;
        if (result > INT_MAX / 10 || result < INT_MIN / 10) {
            return 0;
        }
        x /= 10;
    }
    return result;
}

int main() {
    int x;
    std::cin >> x;

    std::cout << reverse(x) << std::endl;
    std::cout << INT_MAX;
}

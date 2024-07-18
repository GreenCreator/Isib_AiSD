#include <iostream>
#include <vector>
#include <set>

int main() {
    size_t n, k;
    std::cin >> n >> k;

    std::vector<int> numbers(n);
    for (size_t i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::multiset<int> window;

    for (size_t i = 0; i < k; ++i) {
        window.insert(numbers[i]);
    }

    std::cout << *window.begin() << std::endl;

    for (size_t i = k; i < n; ++i) {
        window.erase(window.find(numbers[i - k]));
        window.insert(numbers[i]);
        std::cout << *window.begin() << std::endl;
    }

    return 0;
}

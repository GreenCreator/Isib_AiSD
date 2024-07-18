#include <vector>
#include <iostream>
#include <algorithm>

void Input(std::vector<int> &vector) {
    int number;
    for (size_t i = 0; i < vector.size(); ++i) {
        std::cin >> number;
        vector[i] = number;
    }
}

int main() {
    size_t n;
    size_t k;
    std::cin >> n >> k;

    std::vector<int> vector_1(n);
    std::vector<int> vector_2(k);

    Input(vector_1);
    Input(vector_2);

    for (auto item: vector_2) {
        auto it = std::lower_bound(vector_1.begin(), vector_1.end(), item);

        if (it == vector_1.end()) {
            std::cout << vector_1.back() << std::endl;
        } else if (it == vector_1.begin()) {
            std::cout << vector_1.front() << std::endl;
        } else {
            auto prev = it - 1;
            if (std::abs(*it - item) < std::abs(*prev - item) ||
                (std::abs(*it - item) == std::abs(*prev - item) && *it < *prev)) {
                std::cout << *it << std::endl;
            } else {
                std::cout << *prev << std::endl;
            }
        }
    }

}
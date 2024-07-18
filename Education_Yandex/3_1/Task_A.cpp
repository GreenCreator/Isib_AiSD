#include <iostream>
#include <vector>

template <typename T>
void Print(const T &vector, const char *delimiter) {
    int count = 0;
    for (const auto &item: vector) {
        ++count;
        std::cout << item;
        if (vector.size() != count) {
            std::cout << delimiter;
        }
    }
}

int main() {
    std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", ");  // 1, 2, 3, 4
}


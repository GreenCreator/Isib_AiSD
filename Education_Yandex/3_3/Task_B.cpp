#include <iostream>
#include <vector>

template<typename Iter>
Iter Unique(Iter first, Iter last) {
    if (first == last) return last;

    Iter result = first;

    while (++first != last) {
        if (*result != *first) {
            *(++result) = *first;
        }
    }

    return ++result;
}

int main() {
    std::vector<int> vector{1, 1, 3, 4, 5};
    Unique(vector.begin(), vector.end());

    for (auto it = vector.begin(); it != vector.end(); ++it) {
        std::cout << *it << " ";  //
    }
}
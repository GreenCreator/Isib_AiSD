#include <vector>
#include <iostream>

template<typename T>
void Duplicate(std::vector<T> &v) {
    std::vector<T> copy;
    copy.resize(v.size());
    std::copy(v.begin(), v.end(), copy.begin());

    for (auto it = v.begin(); it != v.end(); ++it) {
        copy.push_back(*it);
    }
    v = copy;
}

int main() {

    std::vector<int> vector{1, 2, 3};
    Duplicate(vector);
    for (auto v: vector) {
        std::cout << v << " ";
    }
}
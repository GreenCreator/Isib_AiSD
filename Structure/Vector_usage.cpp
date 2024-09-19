#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>

void procedure(int x) {
    std::cout << x << " ";
}

int main() {
//    std::list<int> a;
    std::vector<int> a;

    for (int i = 0; i < 10; ++i) {
        a.push_back(i);
    }

    auto iter = a.begin();
    while (iter != a.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl;
    for (auto it = a.begin(); it != a.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::for_each(a.begin(), a.end(), procedure);

    std::cout << std::endl;
    for (auto &elem: a) {
        std::cout << elem << " ";
    }

    return 0;
}
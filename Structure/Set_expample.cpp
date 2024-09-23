#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <set>

void procedure(int x) {
    std::cout << x << " ";
}

int main() {
    std::set<int> words;

    for (int i = 10; i > 0; --i) {
        words.insert(i);
    }

    auto iter = words.begin();
    while (iter != words.end()) {
        std::cout << *iter << " ";
        ++iter;
    }
    std::cout << std::endl;
    for (auto it = words.begin(); it != words.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::for_each(words.begin(), words.end(), procedure);

    std::cout << std::endl;
    for (auto &elem: words) {
        std::cout << elem << " ";
    }

    return 0;
}
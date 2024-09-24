#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
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
    std::cout << std::endl;
    std::cout << "Enter key to find in set: ";
    int number;
    std::cin >> number;
    if (words.find(number) != words.end()) {
        std::cout << "Find! elem in " << *words.find(number);
    } else {
        std::cout << "Not found";
    }

    return 0;
}
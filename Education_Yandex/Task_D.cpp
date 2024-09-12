#include <vector>
#include <algorithm>
#include "iostream"

int main() {
    std::string line;
    std::vector<std::string> words;
    while (std::getline(std::cin, line)) {
        words.push_back(line);
    }

    std::sort(words.begin(), words.end(), std::greater<std::string>());

    for (const auto &str: words) {
        std::cout << str << std::endl;
    }
}
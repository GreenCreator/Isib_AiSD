#include <iostream>
#include <vector>
#include <map>
#include <set>

int main() {
    std::vector<std::string> words;
    std::string word;
    size_t count;
    std::cin >> count;
    count *= 2;
    while (count > 0 && std::cin >> word) {
        --count;
        words.push_back(word);
    }
    std::map<int, std::set<std::string>> book;

    for (size_t i = 0; i < words.size() - 1; i += 2) {
        int number = std::stoi(words[i + 1]);
        book[number].insert(words[i]);
    }

    for (const auto &[number, str]: book) {
        std::cout << number << " ";
        for (const auto &t: str) {
            std::cout << t << " ";
        }
        std::cout << std::endl;

    }
}
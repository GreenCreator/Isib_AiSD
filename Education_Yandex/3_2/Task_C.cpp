#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word) {
        words.push_back(word);
    }

    std::set<std::string> directory;

    for (size_t i = 0; i < words.size(); ++i) {
        std::string buffer;
        for (int j = 0; j < words[i].size(); ++j) {
            buffer += words[i][j];
            if (words[i][j] == '/') {
                directory.insert(buffer);
            }
        }
    }

    for (const auto &t: directory) {
        std::cout << t << std::endl;
    }
}
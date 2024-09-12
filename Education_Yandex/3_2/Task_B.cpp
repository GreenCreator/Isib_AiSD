#include <iostream>
#include <vector>
#include <set>

int main() {
    std::vector<std::string> words;
    std::string word;
    while (std::cin >> word) {
        words.push_back(word);
    }

    std::set<char> letters(words[0].begin(), words[0].end());

    for (size_t i = 1; i < words.size(); ++i) {
        std::set<char> current_letters(words[i].begin(), words[i].end());
        std::set<char> new_common_letters;

        for (char c : letters) {
            if (current_letters.find(c) != current_letters.end()) {
                new_common_letters.insert(c);
            }
        }

        letters = std::move(new_common_letters);
    }

    for (const auto &ch: letters) {
        std::cout << ch;
    }
}
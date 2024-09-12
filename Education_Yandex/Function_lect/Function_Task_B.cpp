#include <iostream>
#include <vector>

std::string CommonPrefix(const std::vector<std::string> &words) {
    if (words.empty()) {
        return "";
    }

    std::string prefix = words[0];

    int count = 0;

    for (size_t j = 0; j < prefix.size(); ++j) {

        for (size_t i = 0; i < words.size(); ++i) {

            if (prefix[j] == words[i][j]) {
                continue;
            } else {
                return prefix.substr(0, count);
            }

        }
        ++count;
    }
    return prefix.substr(0, count);
}

int main() {

    std::vector<std::string> words{"appricot", "apple", "application"};


    std::cout << CommonPrefix(words);

}
#include <iostream>
#include <vector>

std::vector<std::string> Split(const std::string &str, char delimiter) {
    std::vector<std::string> result;
    if (str.empty()) {
        result.push_back("");
        return result;
    }

    std::string word;

    for (const auto &ch: str) {
        if (ch == delimiter) {
            result.push_back(word);
            word = "";
            continue;
        }
        word += ch;
    }
    result.push_back(word);

    return result;
}

int main() {
    auto split = Split("_What_is_your_name?", '_');

    for (const auto &text: split) {
        std::cout << text << std::endl;
    }
}
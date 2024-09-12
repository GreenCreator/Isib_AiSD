#include <iostream>
#include <vector>

std::string Join(const std::vector<std::string> &tokens, char delimiter) {
    if (tokens.empty()) {
        return "";
    }

    std::string str = tokens[0];
    for (size_t i = 1; i < tokens.size(); ++i) {
        str += delimiter;
        str += tokens[i];
    }
    return str;
}

int main() {
    std::vector<std::string> token{{"What", "is", "your", "name?"}};

    std::cout << Join(token, '_');
}
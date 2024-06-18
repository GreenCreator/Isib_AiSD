#include <algorithm>
#include "iostream"

std::string removeSpaces(const std::string &str) {
    std::string result;
    for (char c: str) {
        if (c != ' ') {
            result += c;
        }
    }
    return result;
}

int main() {
    std::string line;

    std::getline(std::cin, line);

    line = removeSpaces(line);

    std::string revers = line;
    std::reverse(revers.begin(), revers.end());
    if (line == revers) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

}
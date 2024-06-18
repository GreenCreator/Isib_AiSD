#include <iostream>
#include <string>
#include <unordered_map>

std::string soundex(const std::string& word) {
    if (word.empty()) return "0000";

    std::string result;
    result += word[0];

    std::unordered_map<char, char> charToDigit = {
            {'b', '1'}, {'f', '1'}, {'p', '1'}, {'v', '1'},
            {'c', '2'}, {'g', '2'}, {'j', '2'}, {'k', '2'},
            {'q', '2'}, {'s', '2'}, {'x', '2'}, {'z', '2'},
            {'d', '3'}, {'t', '3'},
            {'l', '4'},
            {'m', '5'}, {'n', '5'},
            {'r', '6'}
    };

    char last_digit = 0;
    for (size_t i = 1; i < word.size(); ++i) {
        char ch = word[i];
        if (ch == 'a' || ch == 'e' || ch == 'h' || ch == 'i' ||
            ch == 'o' || ch == 'u' || ch == 'w' || ch == 'y') {
            continue;
        }
        if (charToDigit.find(ch) != charToDigit.end()) {
            char current_digit = charToDigit[ch];
            if (current_digit != last_digit) {
                result += current_digit;
                last_digit = current_digit;
            }
        }
    }

    result = result.substr(0, 4);
    while (result.size() < 4) {
        result += '0';
    }

    return result;
}

int main() {
    std::string word;
    std::cin >> word;
    std::string soundex_code = soundex(word);
    std::cout << soundex_code << std::endl;
    return 0;
}
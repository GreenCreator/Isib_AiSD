#include <string>
#include <iostream>

int myAtoi(std::string s) {
    if (s.empty()) {
        return 0;
    }
    int sign = 1;
    int result = 0;
    int i = 0;

    while (i < s.size() && s[i] == ' ') {
        i++;
    }

    if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
        if (s[i] == '-') {
            sign = -1;
        }
        i++;
    }

    while (i < s.size() && isdigit(s[i])) {
        int digit = s[i] - '0';

        if (result > (INT_MAX - digit) / 10) {
            return sign == 1 ? INT_MAX : INT_MIN;
        }

        result = result * 10 + digit;
        i++;
    }

    return result * sign;
}

int main() {
    std::string line;
    getline(std::cin, line);

    std::cout << myAtoi(line);
}
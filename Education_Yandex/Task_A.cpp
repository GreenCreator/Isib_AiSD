#include <iostream>

bool IsPasswordValidASCII(std::string password) {
    const int ASCII_MIN = 33;
    const int ASCII_MAX = 126;
    for (char ch: password) {
        if (static_cast<int>(ch) < ASCII_MIN || static_cast<int>(ch) > ASCII_MAX) {
            return false;
        }
    }
    return true;
}

bool IsPasswordValidLength(std::string password) {
    if (password.length() >= 8 && password.length() <= 14) {
        return true;
    }
    return false;
}

bool IsPasswordValidClassSymbol(std::string password) {
    size_t count = 0;
    bool isUpper = false;
    bool isLower = false;
    bool isDigit = false;
    bool isOther = false;

    for (char ch: password) {
        if (!isUpper && std::isupper(ch)) {
            isUpper = true;
            ++count;
        }else if (!isLower && std::islower(ch)) {
            isLower = true;
            ++count;
        }else if (!isDigit && std::isdigit(ch)) {
            isDigit = true;
            ++count;
        }else if (!isOther && !std::isalnum(ch)) {
            isOther = true;
            ++count;
        }
    }

    return count >= 3;
}


int main() {
    std::string password;
    std::getline(std::cin, password);

    if (IsPasswordValidASCII(password) && IsPasswordValidLength(password) && IsPasswordValidClassSymbol(password)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }

}
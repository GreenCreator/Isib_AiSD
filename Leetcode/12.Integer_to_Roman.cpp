#include <iostream>

std::string intToRoman(int num) {
    int n[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    std::string s[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int i = 0;
    std::string result;
    while (num > 0) {
        if (num >= n[i]) {
            result += s[i];
            num -= n[i];
        } else {
            i++;
        }
    }
    return result;
}

int main() {
    std::cout << intToRoman(49);
}
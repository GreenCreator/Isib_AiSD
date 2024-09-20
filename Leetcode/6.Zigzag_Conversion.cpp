
#include <string>
#include <iostream>
#include <vector>

std::string convert(std::string s, int numRows) {
    if (numRows == 1 || numRows >= s.length()) {
        return s;
    }
    std::vector<std::vector<char>> rows(numRows);

    int i = 0, d = 1;
    for (char ch : s) {
        rows[i].push_back(ch);
        if (i == 0) {
            d = 1;
        } else if (i == numRows - 1) {
            d = -1;
        }
        i += d;
    }

    std::string result;
    for (const auto& row : rows) {
        for (char c : row) {
            result += c;
        }
    }

    return result;
}



int main() {
    std::string s = "PAYPALISHIRING";

    std::cout << convert(s, 3);
}
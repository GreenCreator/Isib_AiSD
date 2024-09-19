#include <iostream>
#include <vector>
#include <string>

std::string preProcess(const std::string &s) {
    if (s.empty()) return "^$";
    std::string ret = "^";
    for (int i = 0; i < s.size(); i++) {
        ret += "#" + s.substr(i, 1);
    }
    ret += "#$";
    return ret;
}

std::string longestPalindrome(const std::string &s) {
    std::string T = preProcess(s);
    int n = T.size();
    std::vector<int> P(n, 0);
    int C = 0, R = 0;
    for (int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i;

        if (R > i) {
            P[i] = std::min(R - i, P[i_mirror]);
        }

        while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
            P[i]++;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;
    for (int i = 1; i < n - 1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    int start = (centerIndex - 1 - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    std::string s;
    getline(std::cin, s);
    std::cout << longestPalindrome(s) << std::endl;
    return 0;
}

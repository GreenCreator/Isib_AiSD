#include <iostream>
#include <vector>
#include <string>

std::string longestPalindrome(const std::string &s) {
    std::string ans;
    for (int i = 0; i < s.length(); ++i) {
        int l = i;
        int r = i;

        while (l <= r && l >= 0 && r < s.length()) {
            if (s[l] != s[r]) {
                break;
            }
            if (r - l + 1 > ans.length()) {
                ans = s.substr(l, r - l + 1);
            }

            --l;
            ++r;
        }

        l = i;
        r = i + 1;

        while (l <= r && l >= 0 && r < s.length()) {
            if (s[l] != s[r]) {
                break;
            }
            if (r - l + 1 > ans.length()) {
                ans = s.substr(l, r - l + 1);
            }

            --l;
            ++r;
        }

    }
    return ans;
}

int main() {
    std::string s;
    getline(std::cin, s);
    std::cout << longestPalindrome(s) << std::endl;
    return 0;
}

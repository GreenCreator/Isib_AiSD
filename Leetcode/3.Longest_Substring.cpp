#include <string>
#include <iostream>
#include <vector>

int lengthOfLongestSubstring(std::string s) {
    int n = s.length();
    int maxLength = 0;
    std::vector<int> charIndex(128, -1);
    int left = 0;

    for (int right = 0; right < n; right++) {
        if (charIndex[s[right]] >= left) {
            left = charIndex[s[right]] + 1;
        }
        charIndex[s[right]] = right;
        maxLength = std::max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {
    std::string s = "abcabcbb";
    std::cout << lengthOfLongestSubstring(s);
}
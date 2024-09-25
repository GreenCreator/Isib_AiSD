#include <string>
#include <iostream>
#include <map>
#include <unordered_map>

int romanToInt(std::string s) {

    std::unordered_map<char, int> words = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
    };
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        if (words[s[i]] < words[s[i + 1]]) {
            result -= words[s[i]];
        } else {
            result += words[s[i]];
        }
    }
    return result;
}

int main() {
    std::cout << romanToInt("MCMXCIV");
}
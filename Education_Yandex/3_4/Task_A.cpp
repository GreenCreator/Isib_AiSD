#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool isValid(const std::string& s) {
    std::stack<char> stack;
    std::unordered_map<char, char> matching_bracket = {
            {')', '('},
            {']', '['},
            {'}', '{'}
    };

    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else {
            if (stack.empty() || stack.top() != matching_bracket[ch]) {
                return false;
            }
            stack.pop();
        }
    }

    return stack.empty();
}

int main() {
    std::string s;
    std::cin >> s;

    if (isValid(s)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}

#include <vector>
#include <iostream>
#include <string>

std::vector<int> prefix_function_kmp(std::string str) {
    std::vector<int> pi(str.length(), 0);
    for (int i = 1; i < str.length(); ++i) {
        int k = pi[i - 1];
        while (k > 0 && str[i] != str[k]) {
            k = pi[k - 1];
        }
        if (str[i] == str[k]) {
            ++k;
        }
        pi[i] = k;
    }
    return pi;
}

int main() {
    std::string line;
    getline(std::cin, line);
    std::string tmp;
    getline(std::cin, tmp);

    std::string summary = tmp + '#' + line;
    auto pi = prefix_function_kmp(summary);

    int count = 0;
    for (auto x: pi) {
//        std::cout << x << " ";
        if (x == tmp.size()) {
            ++count;
        }
    }
//    std::cout << std::endl;
    std::cout << "Count substr in line: " << count << std::endl;

}
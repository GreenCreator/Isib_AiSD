#include <iostream>
#include <vector>
#include <map>

int main() {
    std::map<int, int> freqNumbers;
    std::vector<std::string> total;
    int number;
    while (std::cin >> number) {
        ++freqNumbers[number];
        if (freqNumbers.at(number) > 1) {
            total.push_back("YES");
        } else {
            total.push_back("NO");
        }
    }
    for (auto t: total) {
        std::cout << t << std::endl;
    }
}
#include <iostream>
#include <vector>

int main() {
    int n = 0;
    std::cin >> n;

    std::vector<int> seatNumber;
    while (n > 0) {
        --n;
        int number;
        std::cin >> number;
        seatNumber.push_back(number);
    }

    std::vector<int> inverseNumber(seatNumber.size());

    for (size_t i = 0; i < inverseNumber.size(); ++i) {
        inverseNumber[seatNumber[i] - 1] = i + 1;
    }

    for (int i = 0; i < inverseNumber.size(); ++i) {
        std::cout << inverseNumber[i] << " ";
    }
}
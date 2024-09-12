#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

int main() {
    size_t k;
    std::cin >> k;

    std::string word;

    std::map<std::string, int> freq;
    while (std::cin >> word) {
        ++freq[word];
    }

    std::vector<std::pair<std::string, int>> freq_vector(freq.begin(), freq.end());

    std::sort(freq_vector.begin(), freq_vector.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second > b.second;
    });

    for (size_t i = 0; i < k && i < freq_vector.size(); ++i) {
        std::cout << freq_vector[i].first << '\t' << freq_vector[i].second << '\n';
    }

    return 0;
}


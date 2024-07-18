#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

void GetNgram(std::vector<std::string> &result, const std::string &word, size_t start, size_t n) {
    if (start + n <= word.size()) {
        std::string str;
        for (size_t i = start; i < start + n; ++i) {
            str += word[i];
        }
        result.push_back(str);

        return GetNgram(result, word, ++start, n);
    }
}

int main() {
    size_t m;
    size_t n;
    std::cin >> m >> n;

    std::vector<std::string> words;
    std::string word;
    while (m > 0) {
        --m;
        std::cin >> word;
        words.push_back(word);
    }
    std::map<std::string, int> ngram;
    std::vector<std::string> ngramWord;
    for (const auto &str: words) {
        ngramWord.clear();
        GetNgram(ngramWord, str, 0, n);
        for (const auto &t: ngramWord) {
            ++ngram[t];
        }
    }

    std::vector<std::pair<std::string, int>> sortedByFreq(
            ngram.begin(),
            ngram.end()
    );

    std::sort(
            sortedByFreq.begin(),
            sortedByFreq.end(),
            [](const auto &p1, const auto &p2) {
                return std::tie(p2.second, p1.first) < std::tie(p1.second, p2.first);
            }
    );

    for (const auto &[str, count]: sortedByFreq) {
        std::cout << str << " - " << count << std::endl;
    }
}
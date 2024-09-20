#include <iostream>
#include <cstdint>
#include <valarray>

const int P = 257;

void search(std::string pattern, std::string txt) {
    int M = pattern.length();
    int N = txt.length();
    int i, j;
    uint64_t p = 0; // hash value for pattern
    uint64_t t = 0; // hash value for txt
    uint64_t h = 1;

    for (i = 0; i < M - 1; i++) {
        h = (h * P) % int(pow(2, P));
    }

    for (i = 0; i < M; i++) {
        p = (P * p + pattern[i]) % int(pow(2, P));
        t = (P * t + txt[i]) % int(pow(2, P));
    }

    for (i = 0; i <= N - M; i++) {

        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pattern[j]) {
                    break;
                }
            }

            if (j == M)
                std::cout << "Pattern found at index " << i << std::endl;
        }

        if (i < N - M) {
            t = (P * (t - txt[i] * h) + txt[i + M]) % int(pow(2, P));
        }
    }
}

int main() {
    std::string txt = "abcabcabcbabbabcbaabcba";
    std::string pattern = "ab";

    search(pattern, txt);
    return 0;
}


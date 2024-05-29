#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

void AddWord(std::vector<char> &vector, char element) {
    bool isCanAdd = true;
    for (int i = 0; i < vector.size(); ++i) {
        if (element == ',' || vector[i] == element) {
            isCanAdd = false;
            break;
        }
    }
    if (isCanAdd) {
        vector.push_back(element);
    }
}

void GenerateCipher(int words, int sumData, int numberFirstWord) {

    std::stringstream cipher;
    cipher << std::hex << (words + sumData * 64 + numberFirstWord * 256);

    std::string cipHex = cipher.str();
    std::transform(cipHex.begin(), cipHex.end(), cipHex.begin(), ::toupper);
    int iterator = 0;

    std::string out;

    for (int i = cipHex.size() - 1; i >= 0; --i) {

        if (cipHex[i] != NULL) {
            out += cipHex[i];
        }

        ++iterator;
        if (iterator > 2) {
            break;
        }
    }

    for (int i = out.size() - iterator; i >= 1; --i) {
        out += "0";
    }


    for (int i = out.size(); i >= 0; --i) {
        if (out[i] != NULL) {
            std::cout << out[i];
        }
    }
    std::cout << " ";
}

int main() {

    int count = 0;
    std::cin >> count;

    std::vector<std::string> input(count);
    for (int i = 0; i < count; ++i) {
        std::cin >> input[i];
    }

    for (int i = 0; i < count; ++i) {
        int countSplit = 0;
        std::vector<char> words;
        int sumDataBirthDay = 0;

        for (int j = 0; j < std::size(input.at(i)); ++j) {

            if (input[i][j] == ',') {
                ++countSplit;
                continue;
            }
            if (countSplit < 3) {//5648
                AddWord(words, input[i][j]);
            } else if (countSplit < 5) {
                sumDataBirthDay += (int) input[i][j] - (int) '0';
            }

        }

        GenerateCipher(words.size(), sumDataBirthDay, (int) input[i][0] - (int) 'A' + 1);
    }

    return 0;
}
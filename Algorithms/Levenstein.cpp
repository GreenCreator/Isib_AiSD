#include <iostream>
#include <vector>


int levenstein_distance(std::string a, std::string b) {
    std::vector<std::vector<int>> L;
    L.resize(a.length() + 1);
    for (int i = 0; i <= a.length(); ++i) {
        L[i].resize(b.length() + 1);
    }
    for (int i = 0; i <= a.length(); ++i) {
        L[i][0] = i;
    }
    for (int i = 0; i <= b.length(); ++i) {
        L[0][i] = i;
    }

    for (int i = 1; i <= a.length(); ++i) {
        for (int k = 1; k <= b.length(); ++k) {
            if (a[i - 1] == b[k - 1]) {
                L[i][k] = L[i - 1][k - 1];
            } else {
                L[i][k] = std::min(std::min(L[i - 1][k], L[i][k - 1]), L[i - 1][k - 1]) + 1;
            }
        }
    }

    return L[a.length()][b.length()];
}

int main() {

    std::string a, b;
    std::cout << "Enter string A:" << std::endl;
    std::cin >> a;
    std::cout << "Enter string B:" << std::endl;
    std::cin >> b;
    std::cout << "Levenstein distance between A and B is: ";
    std::cout << levenstein_distance(a, b);
}
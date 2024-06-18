#include <algorithm>
#include <iostream>
#include <string>

std::string DNAtoRNA(std::string dna){

    for (int i = 0; i < size(dna); ++i) {
        if(dna[i] == 'T'){
            dna[i] = 'U';
        }
    }
    return dna;
}
int main() {
    int sum = 0;
    int x;
    while (std::cin >> x) {
        sum += x;
    }
    std::cout << sum << "\n";
}
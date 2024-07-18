#include <algorithm>
#include <vector>
#include <iostream>

template <typename T>
void PrintResults(T iter1, T iter2){
    for (; iter1 != iter2 ; ++iter1) {
        std::cout << *iter1 << " ";
    }
}

template <typename T>
void Process(const std::vector<T>& data) {

    std::vector<T> filtered(data.size());

    auto filteredLast = std::copy_if(
            data.begin(),
            data.end(),
            filtered.begin(),
            [](const T& x) { return x > 0; }
    );

    PrintResults(filtered.begin(), filteredLast);
}

int main(){
    std::vector<int> first{1,2,3,4};
    Process(first);
}
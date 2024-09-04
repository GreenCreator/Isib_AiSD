#include <iostream>
#include <vector>

void insertionSort(std::vector<int> &array) {
    for (int i = 1; i < array.size(); ++i) {
        int j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            std::swap(array[j - 1], array[j]);
            --j;
        }
    }
}

int main() {

    std::vector<int> inputArray = {4, 3, 12, 1, 5, 5, 3, 9};

    insertionSort(inputArray);

    for (int i = 0; i < inputArray.size(); i++)
        std::cout << inputArray[i] << " ";

    return 0;
}

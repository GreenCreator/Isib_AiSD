#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        for (int j = i + 1; j < array.size(); ++j) {
            if (array[j] < array[i]) {
                std::swap(array[j], array[i]);
            }
        }
    }
}

int main() {

    std::vector<int> inputArray = {4, 3, 12, 1, 5, 5, 3, 9};

    selectionSort(inputArray);

    for (int i = 0; i < inputArray.size(); i++)
        std::cout << inputArray[i] << " ";

    return 0;
}

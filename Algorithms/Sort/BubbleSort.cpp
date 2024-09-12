#include <iostream>
#include <vector>

void bubbleSort(std::vector<int> &array) {
    for (int i = 0; i < array.size() - 1; ++i) {
        bool swapped = false;
        for (int j = 0; j < array.size() - i - 1; ++j) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {

    std::vector<int> inputArray = {4, 3, 12, 1, 5, 5, 3, 9};

    bubbleSort(inputArray);

    for (int i = 0; i < inputArray.size(); i++)
        std::cout << inputArray[i] << " ";

    return 0;
}

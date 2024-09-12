#include <iostream>
#include <string>

int Euclid(int a, int b) {
    while (a != 0 && b != 0) {
        if (b > a) {
            b %= a;
        } else {
            a %= b;
        }
    }
    return a == 0 ? b : a;
}

int LeastComminFactor(int a, int b) {
    return a * b / Euclid(a, b);
}

void Decomposition(int number) {
    int divider = 2;
    while (number != 1) {
        if (number % divider == 0) {
            std::cout << divider;
            number /= divider;
        } else {
            ++divider;
        }
    }
}

int BinarySearch(int *arr, int size, int find) {
    int left = 0;
    int right = size;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (arr[middle] == find) {
            return middle;
        }
        if (arr[middle] > find) {
            right = middle - 1;
        } else if (arr[middle] < find) {
            left = middle + 1;
        }
    }
    return -1;
}

template<typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void SelectionSort(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[i]) {
                swap(arr[j], arr[i]);
            }
        }
    }
}

void InserionSort(int *arr, int size) {
    for (int i = 0; i < size; ++i) {
        int j = i + 1;
        while (j > 0 && arr[j - 1] < arr[j]) {
            std::swap(arr[j - 1], arr[j]);
            --j;
        }

    }
}


int main() {

    int arr[]{5, 4, 4, 4, 1};
    int size_arr = sizeof(arr) / sizeof(arr[0]);
    SelectionSort(arr, size_arr);
    std::cout << BinarySearch(arr, size_arr, 5) << std::endl;
    return 0;
}


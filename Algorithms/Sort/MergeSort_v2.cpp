#include <iostream>
#include <cstdint>
#include <vector>

void merge_sort(int *arr, int arr_size) {

    if (arr_size <= 1) return;

    int middle = arr_size / 2;
    int *left = arr;
    int *right = arr + middle;
    int left_size = middle;
    int right_size = arr_size - left_size;

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    int *buffer = new int[arr_size];
    int left_i = 0;
    int right_i = 0;
    int buffer_i = 0;

    while (left_i < left_size && right_i < right_size) {
        if (left[left_i] <= right[right_i]) {
            buffer[buffer_i] = left[left_i];
            ++left_i;
            ++buffer_i;
        } else {
            buffer[buffer_i] = right[right_i];
            ++right_i;
            ++buffer_i;
        }
    }

    while (left_i < left_size) {
        buffer[buffer_i] = left[left_i];
        ++left_i;
        ++buffer_i;
    }

    while (right_i < right_size) {
        buffer[buffer_i] = right[right_i];
        ++right_i;
        ++buffer_i;
    }

    for (int i = 0; i < arr_size; ++i) {
        arr[i] = buffer[i];
    }

    delete[] buffer;


}


int main() {
    int arr[]{3, 1, 4, 6, 2, 10, 1, 0};
    merge_sort(arr, std::size(arr));

    for (int i: arr) {
        std::cout << i << " ";
    }
}
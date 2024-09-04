#include "iostream"

void Merge(int *arr, int len_arr, int *arr2, int len_arr2, int *buffer) {

    int index_L = 0;
    int index_R = 0;

    while (index_L < len_arr && index_R < len_arr2) {
        if (arr[index_L] <= arr2[index_R]) {
            buffer[index_L + index_R] = arr[index_L];
            ++index_L;
        } else {
            buffer[index_L + index_R] = arr2[index_R];
            ++index_R;
        }
    }

    while (index_L < len_arr) {
        buffer[index_L + index_R] = arr[index_L];
        ++index_L;
    }

    while (index_R < len_arr2) {
        buffer[index_L + index_R] = arr2[index_R];
        ++index_R;
    }

    for (int i = 0; i < len_arr + len_arr2; ++i) {
        arr[i] = buffer[i];
    }

}


void RecursiveMergeSort(int *arr, int len_arr, int *buffer) {
    if (len_arr == 1) {
        return;
    }
    int middle = len_arr / 2;
    RecursiveMergeSort(arr, middle, buffer);
    RecursiveMergeSort(arr + middle, len_arr - middle, buffer);

    Merge(arr, middle, arr + middle, len_arr - middle, buffer);
}


void MergeSort(int *arr, int len_arr) {

    int *buffer = new int[len_arr];

    RecursiveMergeSort(arr, len_arr, buffer);
    delete[] buffer;

}


int main() {
    int arr[]{3, 1, 4, 6, 2, 10, 1, 0};
    MergeSort(arr, std::size(arr));

    for (int elem: arr) {
        std::cout << elem << " ";
    }
}
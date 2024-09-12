#include "iostream"

int *Merge(int *arr, int len_arr, int *arr2, int len_arr2) {

    int index_L = 0;
    int index_R = 0;

    int *result = new int[len_arr + len_arr2];

    while (index_L < len_arr && index_R < len_arr2) {
        if (arr[index_L] <= arr2[index_R]) {
            result[index_L + index_R] = arr[index_L];
            ++index_L;
        } else {
            result[index_L + index_R] = arr2[index_R];
            ++index_R;
        }
    }

    while (index_L < len_arr) {
        result[index_L + index_R] = arr[index_L];
        ++index_L;
    }

    while (index_R < len_arr2) {
        result[index_L + index_R] = arr2[index_R];
        ++index_R;
    }

    return result;
}

int main() {

    int arr[]{1, 4, 5, 7, 9, 15};
    int arr2[]{1, 2, 3, 4, 5, 6};

    auto mergeArr = Merge(arr, std::size(arr), arr2, std::size(arr2));

    for (int i = 0; i < std::size(arr) + std::size(arr2); ++i) {
        std::cout << mergeArr[i] << " ";
    }
}
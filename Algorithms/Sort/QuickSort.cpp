#include <iostream>

int Partition(int *arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

void QuickSort(int *arr, int left, int right) {
    if (right <= left) {
        return;
    }

    int p = Partition(arr, left, right);
    QuickSort(arr, left, p - 1);
    QuickSort(arr, p + 1, right);
}


int main() {
    int arr[]{3, 1, 4, 6, 2, 10, 1, 0};
//    int arr[]{1, 2, 3, 4, 5, 6, 7, 8};
    QuickSort(arr, 0, std::size(arr) - 1);

    for (int elem: arr) {
        std::cout << elem << " ";
    }
}


//
//
//int Partition(int *arr, int left, int right) {
//    int pivot = arr[(left + right) / 2];
//    while (left < right) {
//        while (arr[left] < pivot) {
//            left++;
//        }
//        while (arr[right] >= pivot) {
//            right--;
//        }
//        if (left <= right) {
//            std::swap(arr[left], arr[right]);
//        }
//    }
//    std::swap(arr[left], arr[right]);
//    std::cout << left << " " << right << std::endl;
//    return left;
//}
#include "math.h"
#include "iostream"

void SiftUp(int *arr, int id) {
    while (id > 0) {
        int id_parent = trunc(floor(id - 1) / 2);
        if (arr[id_parent] < arr[id]) {
            std::swap(arr[id_parent], arr[id]);
            id = id_parent;
        } else {
            break;
        }
    }
}

void SiftDown(int *arr, int size_arr, int id) {
    while (id < size_arr) {
        int id_ch1 = id * 2 + 1;
        int id_ch2 = id * 2 + 2;

        int id_max = id;

        if (id_ch1 < size_arr && arr[id_ch1] > arr[id_max]) {
            id_max = id_ch1;
        }
        if (id_ch2 < size_arr && arr[id_ch2] > arr[id_max]) {
            id_max = id_ch2;
        }
        if (id != id_max) {

            std::swap(arr[id], arr[id_max]);
        } else {
            break;
        }
    }

}

void ExtractMax(int *arr, int size_arr) {
    std::swap(arr[0], arr[size_arr - 1]);
    size_arr--;
    int max = arr[size_arr];
    SiftDown(arr, size_arr, 0);
}

int main() {

    return 0;
}

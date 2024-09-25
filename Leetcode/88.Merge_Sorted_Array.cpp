#include <vector>
#include <iostream>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int m_index = m - 1;
    int n_index = n - 1;
    int right = m + n - 1;

    while (n_index >= 0) {
        if (m_index >= 0 && nums1[m_index] > nums2[n_index]) {
            nums1[right] = nums1[m_index];
            m_index--;
        } else {
            nums1[right] = nums2[n_index];
            n_index--;
        }
        right--;
    }
    for (int i: nums1) {
        std::cout << i << " ";
    }
}

int main() {
    std::vector<int> nums1{1, 2, 3, 0, 0, 0};
    std::vector<int> nums2{2, 5, 6};

    merge(nums1, 3, nums2, 3);
//    for (int i: nums1) {
//        std::cout << i << " ";
//    }
}

#include <vector>
#include <iostream>

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    std::vector<int> result(nums1.size() + nums2.size());

    int index_L = 0;
    int index_R = 0;

    while (index_L < nums1.size() && index_R < nums2.size()) {
        if (nums1[index_L] <= nums2[index_R]) {
            result[index_L + index_R] = nums1[index_L];
            ++index_L;
        } else {
            result[index_L + index_R] = nums2[index_R];
            ++index_R;
        }
    }

    while (index_L < nums1.size()) {
        result[index_L + index_R] = nums1[index_L];
        ++index_L;
    }

    while (index_R < nums2.size()) {
        result[index_L + index_R] = nums2[index_R];
        ++index_R;
    }

    double median;
    if (result.size() % 2 != 0) {
        median = result[result.size() / 2];
    } else {
        int len = result.size() - 1;
        median = (result[len / 2] + result[len / 2 + 1]) / 2.0;
    }

    return median;
}

int main() {
    std::vector nums1{1, 2};
    std::vector nums2{3, 4};

    std::cout << findMedianSortedArrays(nums1, nums2);
}
#include <vector>
#include <iostream>

std::vector<int> productExceptSelf(std::vector<int> &nums) {
    std::vector<int> result;
    result.push_back(1);
    for (int i = 0; i < nums.size() - 1; ++i) {
        result.push_back(result[i] * nums[i]);
    }
    int tmp = 1;
    for (int i = nums.size() - 2; i >= 0; --i) {
        tmp *= nums[i + 1];
        result[i] *= tmp;
    }

    return result;
}

int main() {
    std::vector nums{1, 2, 3, 4};

    auto result = productExceptSelf(nums);

    for (auto n: result) {
        std::cout << n << " ";
    }
}
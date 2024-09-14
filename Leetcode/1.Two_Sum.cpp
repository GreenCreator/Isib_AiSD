#include <vector>
#include <iostream>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int> &nums, int target) {
    std::unordered_map<int, int> hashMap;
    for (int i = 0; i < nums.size(); ++i) {
        int num = target - nums[i];
        if (hashMap.find(num) != hashMap.end()) {
            return {hashMap[num], i};
        }
        hashMap[nums[i]] = i;
    }
    return {};
}

int main() {
    std::vector<int> nums{3, 2, 3};
    auto out = twoSum(nums, 6);

    for (int i: out) {
        std::cout << i << " ";
    }
}
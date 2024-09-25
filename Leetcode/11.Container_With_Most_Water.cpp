#include <vector>
#include <iostream>

int maxArea(std::vector<int> &height) {

    int l = 0;
    int r = height.size() - 1;
    int max = 0;
    while (l < r) {
        int h = std::min(height[l], height[r]);
        int current_max = h * (r - l);
        if (current_max > max) {
            max = current_max;
        }
        height[l] < height[r] ? ++l : --r;
    }

    return max;
}

int main() {
    std::vector<int> height{2, 3, 4, 5, 18, 17, 6};
    std::cout << maxArea(height);
}
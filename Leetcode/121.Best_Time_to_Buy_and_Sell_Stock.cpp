#include <vector>
#include <limits>

int maxProfit(std::vector<int> &prices) {
    int min = std::numeric_limits<int>::max();
    int max = 0;
    for (auto const &num: prices) {
        min = std::min(min, num);
        max = std::max(max, num - min);
    }
    return max;
}
//[7,1,5,3,6,4] => 5
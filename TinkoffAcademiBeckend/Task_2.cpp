#include <iostream>
#include <vector>
#include <string>
#include <map>

std::pair<int, int> find_max_free_period(std::vector<bool> &occupied) {

    int max_len = 0;
    int start_day = -1;
    int current_start = -1;
    int current_len = 0;

    for (int i = 0; i < occupied.size(); ++i) {
        if (!occupied[i]) {
            if (current_len == 0) {
                current_start = i;
            }
            current_len += 1;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
                start_day = current_start;
            }
            current_len = 0;
        }
    }

    if (current_len > max_len) {
        max_len = current_len;
        start_day = current_start;
    }

    if (max_len == 0) {
        return {0, 0};
    }

    return {start_day + 1, start_day + max_len};
}

int main() {
    std::map<std::string, int> day_to_num = {
            {"MON", 0},
            {"TUE", 1},
            {"WED", 2},
            {"THU", 3},
            {"FRI", 4},
            {"SAT", 5},
            {"SUN", 6}
    };
    std::vector<bool> occupied(28, false);

    std::string days;
    std::string day;
    size_t week = 4;
    while (week > 0) {
        --week;
        std::getline(std::cin, days);

        days += " ";
        for (auto ch: days) {
            if (ch != ' ') {
                day += ch;
            } else if (days != " ") {
                int day_num = day_to_num[day] + (3 - week) * 7;
                occupied[day_num] = true;
                day = "";
            }
        }
    }

    auto result = find_max_free_period(occupied);

    std::cout << result.first << " " << result.second << std::endl;

    return 0;
}

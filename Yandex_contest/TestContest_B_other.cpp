#include <iostream>
#include <vector>
#include <algorithm>

struct Rocket {
    int id;
    int time;
    char status;
};

void CountMinWay(std::vector<int> &count_min, int count, std::vector<Rocket> &table) {
    int cnt = 0;
    for (int i = 0; i < count - 1; ++i) {
        if (table[i].id == table[i + 1].id && table[i + 1].status != 'A') {
            cnt += table[i + 1].time - table[i].time;
        }
        if (table[i].id != table[i + 1].id) {
            count_min.push_back(cnt);
            cnt = 0;
        }
    }
    count_min.push_back(cnt);
}

bool Compare(Rocket rocket_1, Rocket rocket_2) {
    if (rocket_1.id == rocket_2.id) {
        return rocket_1.time < rocket_2.time;
    }
    return rocket_1.id < rocket_2.id;
}

int main() {
    int count = 0;
    std::cin >> count;
    std::vector<Rocket> table(count);
    for (int i = 0; i < count; ++i) {
        int day;
        int hour;
        int min;
        int id;
        char status;
        std::cin >> day >> hour >> min >> id >> status;
        Rocket rocket{id, day * 1440 + hour * 60 + min, status};
        table[i] = rocket;
    }
    std::sort(table.begin(), table.end(), Compare);
    std::vector<int> count_min;
    CountMinWay(count_min, count, table);
    for (int min: count_min) {
        std::cout << min << ' ';
    }

    return 0;
}
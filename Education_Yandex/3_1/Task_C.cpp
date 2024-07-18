#include <iostream>
#include <deque>

void MakeTrain() {
    std::deque<int> trains;
    std::string task;
    size_t count;

    while (std::cin >> task >> count) {
        if (task == "+left") {
            trains.push_front(count);

        } else if (task == "+right") {
            trains.push_back(count);

        } else if (count >= trains.size()) {
            trains.clear();
        } else if (task == "-left") {
            trains.erase(trains.begin(), trains.begin() + count);

        } else if (task == "-right") {
            trains.erase(trains.end() - count, trains.end());
        }
    }
    for (int train: trains) {
        std::cout << train << " ";
    }
}

int main() {
    int count;
    std::cin >> count;
    while (count > 0) {
        --count;
        MakeTrain();
    }
}


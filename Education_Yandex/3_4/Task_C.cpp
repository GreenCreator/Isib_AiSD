#include <iostream>
#include <queue>

void Clear(std::priority_queue<int> &pq) {
    while (!pq.empty()) {
        pq.pop();
    }
}

void Add(std::priority_queue<int> &pq, int value) {
    pq.push(value);
}

void Extract(std::priority_queue<int> &pq) {
    if (!pq.empty()) {
        std::cout << pq.top() << std::endl;
        pq.pop();
    } else {
        std::cout << "CANNOT" << std::endl;
    }
}

int main() {
    std::priority_queue<int> pq;
    std::string line;
    while (std::cin >> line) {
        if (line == "ADD") {
            int number;
            std::cin >> number;
            Add(pq, number);
        }
        if (line == "CLEAR") {
            Clear(pq);
        }
        if (line == "EXTRACT") {
            Extract(pq);
        }
    }
    return 0;
}

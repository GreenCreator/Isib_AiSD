#include <iostream>
#include <vector>
#include <deque>

int main() {
    int n;
    int m;
    std::cin >> n;

    std::deque<std::string> student;
    std::vector<int> job;

    while (n > 0) {
        --n;
        std::string name;
        std::string type;
        std::cin >> name >> type;
        if (type == "top") {
            student.push_front(name);
        } else {
            student.push_back(name);
        }
    }

    std::cin >> m;

    while (m > 0) {
        --m;
        int number;
        std::cin >> number;
        job.push_back(number);
    }

    for (auto numb: job) {
        std::cout << student[numb - 1] << std::endl;
    }

}


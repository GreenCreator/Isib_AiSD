#include <iostream>
#include <vector>

///Backpack packing task

double maxBackpackValue(std::vector<std::pair<int, double>> treasures, int capacity) {
    std::vector<std::vector<double>> F;
    F.resize(capacity + 1);
    for (int i = 0; i <= capacity; ++i) {
        F[i].resize(treasures.size() + 1);
    }
    for (int i = 0; i <= capacity; ++i) {
        F[i][0] = 0;
    }
    for (int i = 0; i <= treasures.size(); ++i) {
        F[0][i] = 0;
    }

    for (int j = 1; j <= treasures.size(); ++j) {
        int weight = treasures[j - 1].first;
        double value = treasures[j - 1].second;
        for (int i = 1; i < weight; ++i) {
            F[i][j] = F[i][j - 1];
        }
        for (int i = weight; i <= capacity; ++i) {
            F[i][j] = std::max(F[i][j - 1], value + F[i - weight][j - 1]);
        }
    }

    return F[capacity][treasures.size()];
}

int main() {

    std::vector<std::pair<int, double>> treasures;

    int treas_numb;
    std::cout << "Enter number of treasures:" << std::endl;
    std::cin >> treas_numb;

    for (int i = 0; i < treas_numb; ++i) {
        int weight;
        double value;
        std::cout << "Enter [" << i << "] treasure weight & value:" << std::endl;
        std::cin >> weight >> value;
        treasures.push_back(std::make_pair(weight, value));
    }

    int capacity;
    std::cout << "Enter capacity backpack:" << std::endl;
    std::cin >> capacity;
    std::cout << maxBackpackValue(treasures, capacity) << "\t";
}
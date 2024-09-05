#include <iostream>

int min_cost(int n, int *price) {

    int cost[n + 1];
    cost[1] = price[1];
    cost[2] = price[1] + price[2];
    for (int i = 3; i <= n; ++i) {
        cost[i] = std::min(cost[i - 1], cost[i - 2]) + price[i];
    }

    std::cout << std::endl << "Min cost path = [ " << n << " ";
    int current = n;
    while (current != 1) {
        if (cost[current - 1] == cost[current] - price[current]) {
            current -= 1;
        } else {
            current -= 2;
        }
        std::cout << current << " ";
    }

    std::cout << "]" << std::endl;
    std::cout << "Min cost: " << cost[n];
    return cost[n];
}

int main() {

    int n;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n;

    int price[n + 1];
    std::cout << "Enter prices of visiting point (from 1 to n)" << std::endl;
    for (int i = 1; i <= n; ++i) {
        std::cin >> price[i];
    }

    min_cost(n, price);
}
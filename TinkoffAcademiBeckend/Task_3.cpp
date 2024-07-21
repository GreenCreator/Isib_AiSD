#include <iostream>
#include <cmath>

long long lcg(long long a, long long e, long long m) {
    return (a * e + 11) % m;
}

int generate_coin(long long &seed, long long a, long long m) {
    seed = lcg(a, seed, m);
    return (abs(seed % 3 - 1) * 5 + abs(seed % 3) * 2) % 8;
}

int main() {
    long long n, k, a, m;
    std::cin >> n >> k >> a >> m;

    long long seed = 0;
    long long total_coins = 0;
    long long total_candies = 0;
    long long current_sum = 0;

    while (total_candies < n) {
        int coin = generate_coin(seed, a, m);
        current_sum += coin;
        total_coins++;

        if (current_sum >= 3 * k) {
            long long candies_this_purchase = current_sum / 3;
            long long purchases = candies_this_purchase / k;

            total_candies += purchases * k + 1;
            current_sum -= purchases * k * 3;

            if (total_candies >= n) {
                break;
            }
        }
    }

    std::cout << total_coins << std::endl;
    return 0;
}

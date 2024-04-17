#include <iostream>
#include <cstdint>

int main() {
  int64_t number, sum = 0;
  std::cin >> number;

  for (sum = 0; number != 0; number /= 10) {
    sum += number % 10;
  }

  std::cout << sum;
  return 0;
}

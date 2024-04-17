#include <iostream>

int main() {
  int max = 0, prev_max = 0, number = -1;

  while (number != 0) {
    std::cin >> number;

    if (max <= number) {
      prev_max = max;
      max = number;
    }

    if (prev_max < number && number < max) {
      prev_max = number;
    }
  }
  std::cout << prev_max;

  return 0;
}

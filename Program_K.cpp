#include <iostream>

int main() {

  int number_1, number_2;
  std::cin >> number_1 >> number_2;

  std::cout << (number_1 + number_2 + abs(number_1 - number_2)) / 2;

  return 0;
}
#include <iostream>

int main() {
  int number, first, second, third;
  std::cin >> number;
  first = number / 100;
  second = number / 10 % 10;
  third = number % 10;
  std::cout << first + second + third;
  return 0;
}
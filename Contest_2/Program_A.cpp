#include <iostream>

int main() {
  int number_1, number_2, number_3;
  std::cin >> number_1 >> number_2 >> number_3;

  if (number_1 > number_2 && number_1 > number_3) {
    std::cout << number_1;
  } else if (number_2 > number_3) {
    std::cout << number_2;
  } else {
    std::cout << number_3;
  }
  return 0;
}

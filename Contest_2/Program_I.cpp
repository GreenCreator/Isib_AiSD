#include <iostream>

int main() {
  int number;
  std::cin >> number;

  int a = 0, b = 1;
  for (int i = 2; i <= number; i++) {
    int f = a + b;
    a = b;
    b = f;
  }
  if (number == 0) {
    b = 0;
  }
  std::cout << b;
  return 0;
}

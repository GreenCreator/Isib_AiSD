#include <iostream>

int main() {

  int n, nextNumber;
  std::cin >> n;

  nextNumber = n + (n + 1) % 2 + 1;

  std::cout << nextNumber;
  return 0;
}
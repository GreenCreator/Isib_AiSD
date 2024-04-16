#include <iostream>

int main() {

  int h, a, b;
  std::cin >> h >> a >> b;

  std::cout << (h - b - 1) / (a - b) + 1;

  return 0;
}
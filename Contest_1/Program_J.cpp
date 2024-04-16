#include <iostream>

int main() {

  int n, m, min, max;
  std::cin >> n >> m;

  min = (n + m - abs(n - m)) / 2;
  max = (n + m + abs(n - m)) / 2;
  std::cout << max % min + 1;

  return 0;
}
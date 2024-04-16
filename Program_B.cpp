#include <iostream>
#include <cmath>

int main() {
  int cathetus_a, cathetus_b;
  std::cin >> cathetus_a >> cathetus_b;
  std::cout << sqrt(pow(cathetus_a, 2) + pow(cathetus_b, 2)) << std::endl;
  return 0;
}
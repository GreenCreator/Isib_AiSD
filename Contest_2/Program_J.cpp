#include <iostream>
#include <cstdint>

int main() {
  int64_t a, b, sum = 0;
  std::cin >> a >> b;

  while (b != 0) {
    sum += a / b;
    int temp = a;
    a = b;
    b = temp % b;
  }
  std::cout << sum;
  return 0;
}

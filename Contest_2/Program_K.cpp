#include <iostream>
#include <cstdint>

int Abbreviation(int a, int b) {
  if (b == 0) {
    return abs(a);
  }
  return Abbreviation(b, a % b);
}

int main() {
  int64_t a, b, c = 0, d = 0;
  std::cin >> a >> b;

  if (a != 0 || b != 0) {
    int divisor = Abbreviation(a, b);

    c = a / divisor;
    d = b / divisor;
  }
  std::cout << c << " " << d << std::endl;

  return 0;
}
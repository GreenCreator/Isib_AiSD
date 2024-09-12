#include <iostream>

/** (ax + b) : (cx + d) = 0
 *  x = -b/a
 */

int main() {
  int a, b, c, d, x, denominator;
  std::cin >> a >> b >> c >> d;
  if (a == 0 && b == 0) {
    std::cout << "INF";
  } else {
    if (a == 0) {
      std::cout << "NO";
    } else {
      x = -b / a;
      denominator = c * x + d;
      if (denominator == 0 || b % a != 0) {
        std::cout << "NO";
      } else {
        std::cout << x;
      }
    }
  }
  return 0;
}

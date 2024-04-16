#include <iostream>

int main() {
  int n, m, k;
  std::cin >> n >> m >> k;

  if (n * m >= k && (k % n == 0 || k % m == 0)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}

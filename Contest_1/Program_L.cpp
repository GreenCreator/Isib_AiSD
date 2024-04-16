#include <iostream>

int main() {

  int number;
  std::cin >> number;

  if (number % 2 == 0) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }

  return 0;
}
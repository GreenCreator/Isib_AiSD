#include <iostream>

int main() {

  int n, second, minutes, hour;
  std::cin >> n;

  second = n % 60 + 100;
  minutes = n / 60 % 60 + 100;
  hour = n / 3600 % 24;

  std::cout << hour << ":" << std::to_string(minutes).substr(1, 2)
            << ":" << std::to_string(second).substr(1, 2);
  return 0;
}
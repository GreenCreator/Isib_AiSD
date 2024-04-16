#include <iostream>

int main() {

  int second_1, second_2, minutes_1, minutes_2, hour_1, hour_2;
  std::cin >> hour_1 >> minutes_1 >> second_1 >> hour_2 >> minutes_2 >> second_2;

  std::cout << (second_2 + minutes_2 * 60 + hour_2 * 3600) - (second_1 + minutes_1 * 60 + hour_1 * 3600);
  return 0;
}
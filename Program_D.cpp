#include <iostream>

int main() {
  int ring_road = 109;
  int speed, time;
  std::cin >> speed >> time;
  std::cout << ((ring_road + speed) * time) % ring_road;
  return 0;
}
#include <iostream>
//TODO: bullshit
int main() {
  int n, m;
  std::cin >> n >> m;
  int temp = 0;
  int incrementY = 0;
  int shiftY = 1;
  int shiftX = 0;
  int incrementX = 0;
  int shiftY_1 = 0;
  int count = n;
  int countY = m - 1;
  bool isFirst = false;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      temp += shiftX;
      shiftY_1++;
      if (j < count) {
        if (i > 0 && isFirst) {
          shiftX = incrementX;
          isFirst = false;
        }
        if (m > shiftX + 1) {
          shiftX++;
        }
      } else if (i != 0) {
        if (countY < shiftY_1) {
          shiftX--;
        }
      }
      std::cout << temp << ' ';
    }
    isFirst = true;
    shiftX = 0;
    shiftY_1 = 0;
    count--;
    countY--;
    if (m > incrementX + 1) {
      incrementX++;
    }
    if (i < m - 1) {
      shiftY++;
    }
    incrementY += shiftY;
    temp = incrementY;
    std::cout << "\n";
  }
  return 0;
}
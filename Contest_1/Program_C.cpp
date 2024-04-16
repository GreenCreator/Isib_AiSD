#include <iostream>

/**
 * Формат ввода
 Вводится целое число, по модулю не превосходящее 10000.

 * Формат вывода
 Выведите сначала фразу "The next number for the number ",
 затем введенное число, затем слово " is ", окруженное пробелами,
 затем формулу для следующего за введенным числа, наконец,
 знак точки без пробела. Аналогично в следующей строке для предыдущего числа.
*/


int main() {
  int number;
  std::cin >> number;
  std::cout << "The next number for the number " << number << " is " << number + 1 << "." << std::endl;
  std::cout << "The previous number for the number " << number << " is " << number - 1 << "." << std::endl;
  return 0;
}
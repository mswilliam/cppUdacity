/*!
 *  \brief    Goal: Practice putting functions in a header file.
 *
 *  \details  Move the function declaration and definition to the header file. Don't forget to include the header file (main.hpp) in the main program.
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-05
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#include<iostream>
#include "main.h"

int main() {
  int m1 = 4;
  int m2 = 5;
  int product;

  product = m1 * m2;

  printProduct(m1, m2, product);
  return 0;
}

void printProduct(int m1, int m2, int product) {
  std::cout << m1 << " * "<< m2 << " = " << product;
}

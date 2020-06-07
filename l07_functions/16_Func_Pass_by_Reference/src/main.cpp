/*!
 *  \file main.cpp
 *  \brief    Goal: Test the operations implementation
 *
 *  \details  call operations functions
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-07
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#include "include/operations.hpp"

int main() {
  uint8_t operation = '*';
  float input1 = 9.8;
  float input2 = 2.3;
  float result;

  if (ErrorFunctionHandler::kOk ==  \
      Calculate(input1, input2, operation, result)) {
    PrintEquation(input1, input2, operation, result);
  }
  return 0;
}

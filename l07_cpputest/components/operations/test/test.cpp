/*!
 *  \file main.cpp
 *  \brief    Goal: Test the operations implementation
 *
 *  \details  call operations functions
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-14
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#include "CppUtest/TestHarness.h"
#include "../include/operations.hpp"

TEST_GROUP (Operations) {

  //  Define data accessible to the test group members here.

  void setup () {
    //  initialization seps are executed before each TEST
  }

  void tearDown () {
    //  ceanup steps are excuted after each TEST
  }
};



/*


int main() {
  uint8_t operation = '*';
  float input1 = 9.8;
  float input2 = 2.3;
  float result;

  if (operations::ErrorFunctionHandler::kOk ==  \
      operations::Calculate(input1, input2, operation, result)) {
    operations::PrintEquation(input1, input2, operation, result);
  }
  return 0;
}
*/
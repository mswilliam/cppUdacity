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

#include "CppUTest/TestHarness.h"
#include "../include/gameboard.h"

TEST_GROUP (Addition) {

  //  Define data accessible to the test group members here.

  void setup () {
    //  initialization steps are executed before each TEST
  }

  void tearDown () {
    //  ceanup steps are excuted after each TEST
  
};

TEST (Addition, ZeroPlusOne) {
  uint8_t operation = '+';
  float input1 = 0.0;
  float input2 = 1.1;
  float result;

  CHECK (operations::ErrorFunctionHandler::kOk == \
      operations::Calculate(input1, input2, operation, result));

  LONGS_EQUAL (1.0, result);
}

TEST (Addition, ZeroPlusZero) {
  uint8_t operation = '+';
  float input1 = 0.0;
  float input2 = 0.0;
  float result;

  CHECK (operations::ErrorFunctionHandler::kOk == \
      operations::Calculate(input1, input2, operation, result));

  LONGS_EQUAL (0.0, result);
}



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

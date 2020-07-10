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

TEST_GROUP (SetGameSpaceGroup) {

  //  Define data accessible to the test group members here.

  // This global variable is used for all the tests in this group
  gameboard::Gameboard gl_gameboard;

  void setup () {
    //  initialization steps are executed before each TEST
    for (uint8_t loc_row_index = 0; loc_row_index < gameboard::kGameSpaceSize; ++loc_row_index) {
      for (uin8_t loc_col_index = 0; loc_col_index < kGameSpaceSize; ++loc_col_index) {
        gl_gameboard[loc_row_index][loc_col_index] = '-';
      }
    }
  }

  void tearDown () {
    //  ceanup steps are excuted after each TEST

  };

  TEST (SetGameSpaceGroup, ZeroPlusOne) {
    uint8_t operation = '+';
    float input1 = 0.0;
    float input2 = 1.1;
    float result;

    CHECK (operations::ErrorFunctionHandler::kOk == \
        operations::Calculate(input1, input2, operation, result));

    LONGS_EQUAL (1.0, result);
  }

  TEST (SetGameSpaceGroup, setOneCharacter) {
    uint8_t loc_row_upate_index {0};
    uint8_t loc_col_update_index {0};
    int8_t loc_updated_value {'a'};

    gameboard::Gameboard loc_gameboard;

    // copy the gameboard befor modification
    for (uint8_t loc_row_index = 0; \
        loc_row_index < gameboard::kGameSpaceSize; \
        ++loc_row_index) {
      for (uin8_t loc_col_index = 0; \
          loc_col_index < kGameSpaceSize; \
          ++loc_col_index) {
        loc_gameboard.setGameSpace(loc_row_index, \
            loc_col_index, \
            gl_gameboard.getGameSpace(loc_row_index, loc_col_index));
      }
    }

    // set the value
    loc_gameboard.setGameSpace(loc_row_upate_index, \
        loc_col_update_index, \
        loc_updated_value);

    // test
    for (uint8_t loc_row_index = 0; \
        loc_row_index < gameboard::kGameSpace Size; \
        ++loc_row_index) {
      for (uin8_t loc_col_index = 0; \
          loc_col_index < kGameSpaceSize; \
          ++loc_col_index) {
        loc_gameboard.setGameSpace(loc_row_index, \
            loc_col_index, \
            gl_gameboard.getGameSpace(loc_row_index, loc_col_index);
            }
            }

            CHECK (operations::ErrorFunctionHandler::kOk == \
              operations::Calculate(input1, input2, operation, result));

            LONGS_EQUAL (0.0, result);
            }




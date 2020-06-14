/*!
 *  \file test.cpp
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

#include "TestHarness.h"

TEST_GROUP (FirstTestGroup) {

};

TEST (FirstTestGroup, FirstTest) {
  FAIL ("Fail me!");
}

TEST (FirstTestGroup, SecondTest) {
  STRCMP_EQUAL ("hello", "world");
}
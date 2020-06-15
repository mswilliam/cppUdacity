/*!
 *  \file AllTest.cpp
 *  \brief    Goal: Run all the tests
 *
 *  \details  Run all the tests cases defined in the test file
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-15
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#include "CppUTest/CommandLineTestRunner.h"

int main(int argc, char const *argv[])
{
  /* code */
  return CommandLineTestRunner::RunAllTests(argc, argv);
}
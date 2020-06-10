/*!
 *  \file operations.cpp
 *  \brief    Goal: implementation of file of operations.hpp.
 *
 *  \details  implementation of calculate and printEquation.
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-07
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#include "../include/operations.hpp"

#include <iostream>



void PrintEquation(const float arg_input1, const float arg_input2,  \
    const uint8_t arg_operation, const float arg_result) {
  std::cout << arg_input1 << " "  \
    << arg_operation << " "       \
    << arg_input2 << " = "        \
    << arg_result << "\n";
}

ErrorFunctionHandler Calculate(\
    const float arg_input1, const float arg_input2, \
    const uint8_t arg_operation, float& arg_result) {
  ErrorFunctionHandler result{ErrorFunctionHandler::kError};
  switch (arg_operation) {
    case '+': {
                arg_result = arg_input1 + arg_input2;
                result = ErrorFunctionHandler::kOk;
              } break;
    case '-': {
                arg_result = arg_input1 - arg_input2;
                result = ErrorFunctionHandler::kOk;
              } break;
    case '*': {
                arg_result = arg_input1 * arg_input2;
                result = ErrorFunctionHandler::kOk;
              } break;
    case '/': {
                if (0.0 <= arg_input2 && arg_input2 <= 0.0) {
                  arg_result = arg_input1 + arg_input2;
                  result = ErrorFunctionHandler::kOk;
                }
              } break;
  }
  return result;
}




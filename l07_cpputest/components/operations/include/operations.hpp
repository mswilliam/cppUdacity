/*!
 *  \file operations.hpp
 *  \brief    Goal: header file operations.hpp
 *
 *  \details  declaration of function
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-07
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#ifndef __OPERATIONS_HPP_
#define __OPERATIONS_HPP_

#include <cstdint>

namespace operations {
  //  \namaspace operations

  enum class ErrorFunctionHandler : uint8_t {
    kOk = 0x00,
    kError = 0x01
  };


  /*! \fn void PrintEquation(const float arg_input1, const float arg_input2, cont uint8_t arg_operation, const float arg_result)
   * \brief A print the equation of the operation
   * \details Print arg_input1 arg_operation  arg_input2 = arg_result 
   *
   * @param[in] arg_input1 The first parameter
   * @param[in] arg_input2 The second parameter
   * @param[in] arg_operation The operation
   * @param[in] arg_result The result of the operation
   */
  void PrintEquation(const float arg_input1, const float arg_input2,  \
      const uint8_t arg_operation, const float arg_result);

  /*! \fn ErrorFunctionHandler Calculate(const float arg_input1, const float arg_in    put2, cont uint8_t arg_operation, float& arg_result)
   * \brief A print the equation of the operation
   * \details Print arg_input1 arg_operation  arg_input2 = arg_result 
   *
   * @param[in] arg_input1 The first parameter
   * @param[in] arg_input2 The second parameter
   * @param[in] arg_operation The operation
   * @param[out] arg_result The result of the operation
   * \return kOk or kError 
   */
  ErrorFunctionHandler Calculate(\
      const float arg_input1, const float arg_input2, \
      const uint8_t arg_operation, float& arg_result);

}  // namespace operations

#endif  // __OPERATIONS_HPP_


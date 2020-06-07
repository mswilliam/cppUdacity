/*!
 *  \file operations.h
 *  \brief    Goal: header file operations.h
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

#ifndef __OPERATIONS_H_
#define __OPERATIONS_H_

/*! \fn       void printEquation(const float arg_input1, const float arg_input2, cont unsigned char arg_operation, const float arg_result)
*   \brief    A print the equation of the operation
*   \details  Print arg_input1 arg_operation  arg_input2 = arg_result 
*
*   @param[in]  arg_input1        The first parameter
*   @param[in]  arg_input2        The second parameter
*   @param[in]  arg_operation     The operation
*   @param[in]  arg_result        The result of the operation
*/
void printEquation(const float arg_input1, const float arg_input2,  \
      cont unsigned char arg_operation, const float arg_result);


#endif  // __OPERATIONS_H_


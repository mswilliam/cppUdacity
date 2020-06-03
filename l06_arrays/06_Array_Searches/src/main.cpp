/*!
 *  \brief    Goal: Practice array manipulation in C++. 
 *  \details  The user will input 40 integers. Put them into an array. Then print the array in the order the numbers were entered. Then print in reverse order. Then sort the array in ascending order and print it. The each print of the array should separate the numbers in the array by one space. For example: the array were [3,4,55] the printout would be 3 4 55
 *  \author   MANGOUA SOFACK William
 *  \version  1.0a
 *  \date     2020-06-01
 *  \copyright GNU Public License.
 *
 *
 *
 * Goal: practice searching an array in C++
 * There is an array of integers. The length of the arrays to be searched 
 * varies. A user will enter an integer and the program will search the array.
 * If the value is in the array, the program will return the location of 
 * the element. If the value is not in the array, the user will be notified 
 * that the value is not in the array. To exit the program the user will enter -1.
 **/

#include <iostream>
#include <cstdio>

int main() {
  const uint8_t ARRAY_SIZE{10};
  int32_t loc_searchArray[ARRAY_SIZE] = \
  {324, 4567, 6789, 5421345, 7, 65, 8965, 12, 342, 485};

  // use loc_searchKey for the number to be found
  // use loc_location for the array index of the found value
  int32_t loc_searchKey{-1};
  uint32_t loc_location{0};
  bool loc_is_not_over{true};

  do {
    std::cout << "Enter the search key\n";
    std::cin >> loc_searchKey;

    if (loc_searchKey != -1) {
      loc_location = 0;
      loc_is_not_over = true;
      while (loc_is_not_over) {
        if (loc_location < ARRAY_SIZE) {
          if (loc_searchArray[loc_location] == loc_searchKey) {
            loc_is_not_over = false;
          } else {
            ++loc_location;
          }
        } else {
          loc_is_not_over = false;
        }
      }

      if (loc_location < ARRAY_SIZE) {
        std::cout << loc_searchKey  \
          << " is at location "     \
          << loc_location           \
          << " in the array.\n";
      } else {
        std::cout << loc_searchKey  \
          <<  " is not in the array.\n";
      }
    }
  }while (loc_searchKey != -1);
  return 0;
}


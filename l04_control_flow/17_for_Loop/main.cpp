/*Write a program that asks a user for five numbers.
 **Print out the sum and average of the five numbers.
 */

#include <iostream>
#include <cstddef>

int main(){
  const uint8_t MAX_INDEX{5};
  int32_t loc_sum{0}, loc_average{0};

  {
    uint8_t loc_index{0};
    uint32_t loc_number{0};

    for( ; loc_index < MAX_INDEX; ++loc_index)
    {
      std::cout << "Give the number " \
        << loc_index + 1
        << "\n";

      std::cin >> loc_number;

      loc_sum += loc_number;
    }
  }

  loc_average = loc_sum / MAX_INDEX;

  std::cout << " The sum is : " \
    << loc_sum                  \
    << " and the average is : " \
    << loc_average
    << "\n";

  return 0;
}

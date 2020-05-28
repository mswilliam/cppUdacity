/*Goal: Practice array manipulation in C++. 
 **The user will input 40 integers. 
 **Put them into an array. Then print the array in the order the numbers were
 **entered. Then print in reverse order. Then sort the array in ascending order 
 **and print it. 
 **The each print of the array should separate the numbers in the array by
 **one space. 
 **For example: the array were [3,4,55] the printout would be 3 4 55
 */

#include <iostream>
#include <stdio.h>

const uint8_t MAX_SIZE{4};

int main()
{
  int32_t loc_userInput[MAX_SIZE];

  //Read the array
  for(uint8_t loc_index{0}; loc_index < MAX_SIZE; ++loc_index)
  {
    std::cout << "Enter the number "  \
      << 1 + loc_index
      << "\n";
    std::cin >> loc_userInput[loc_index];

  }

  //Print the array
  for(uint8_t loc_index{0}; loc_index < MAX_SIZE; ++loc_index)
  {
    std::cout << loc_userInput[loc_index] \
      << " ";
  }
  std::cout << "\n";

  //Print the array in reverse order
  for(uint8_t loc_index{0}; loc_index < MAX_SIZE; ++loc_index)
  {
    std::cout << loc_userInput[MAX_SIZE - loc_index - 1] \
      << " ";
  }
  std::cout << "\n";

  //Sort array
  {
    uint8_t loc_inserted_index{0};
    uint8_t loc_left_index{0};
    uint8_t loc_rigth_index{1};
    bool is_inserted_location_found{false};

    for(uint8_t loc_index{1}; loc_index < MAX_SIZE; ++loc_index)  
    {
      //Insert loc_userInput[loc_index] in [loc_left_index..loc_rigth_index]  
      //find the index to inset into
      loc_left_index = 0;
      loc_rigth_index = loc_index;
      while(false == is_inserted_location_found)
      {
        loc_inserted_index = (loc_left_index + loc_rigth_index) / 2;
        if(loc_userInput[loc_inserted_index] < loc_userInput[loc_index])
        {
          loc_left_index = 1 + loc_inserted_index;
          if(loc_left_index >= loc_rigth_index)
          {
            loc_inserted_index = loc_rigth_index;
            is_inserted_location_found = true;
          }
        }
        else  if(loc_userInput[loc_inserted_index] > loc_userInput[loc_index])
        {
          loc_rigth_index = -1 + loc_inserted_index;
          if(loc_left_index >= loc_rigth_index)
          {
            loc_inserted_index = loc_left_index;
            is_inserted_location_found = true;
          }
        }
        else
        {
          is_inserted_location_found = true;
        }
      }

      if(true == is_inserted_location_found && loc_inserted_index < loc_index)
      {
        //insert at the found position
        int32_t loc_temp{loc_userInput[loc_index]};
        for(uint8_t loc_shift_index{loc_index};       \
          loc_shift_index >= loc_inserted_index + 1;  \
          --loc_shift_index)
        {
          loc_userInput[loc_shift_index] = loc_userInput[loc_shift_index - 1];
        }
        loc_userInput[loc_inserted_index] = loc_temp;
      }
    }
  }

    //Print the array                                             
    for(uint8_t loc_index{0}; loc_index < MAX_SIZE; ++loc_index)
    {
      std::cout << loc_userInput[loc_index] \
        << " ";
    }
    std::cout << "\n";

    return 0;

}

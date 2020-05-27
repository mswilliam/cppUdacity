/*Goal: In the programming quiz, use a while loop to prompt
 **the user to guess a target number. 
 **Tell the user if the guess is too high or too low. 
 **The user enters -1  or guesses the target number to end 
 **the program.
 */

#include <iostream>
#include<sstream>

int main()
{
  //use 55 as the number to be guessed
  const int32_t TARGET{55};
  int32_t loc_guess{-1};
  {
    bool is_not_over{true};
    std::string loc_input{""};
    while(is_not_over)
    {
      std::cout << "Guess a number between 0 and 100: ";
      getline(std::cin, loc_input);
      std::stringstream(loc_input) >> loc_guess;

      if(-1 == loc_guess)
      {
        is_not_over = false;
      }
      else
      {
        if(loc_guess > TARGET)
        {
          std::cout << "the guess is too high.\n";
        }
        else if (loc_guess < TARGET)
        {
          std::cout << "the guess is too low.\n";
        }
        else
        {
          std::cout << "the guess number is correct\n";
          is_not_over = false;
        }
      }
    }
  }
  return 0;
}


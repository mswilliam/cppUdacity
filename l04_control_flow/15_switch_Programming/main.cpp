/*Now I would like you to do a switch statement with breaks
 **between the cases. Create a program that asks the user for
 **two float numbers. Then asks the user if they would like to:
 **add the numbers, subtract the numbers, multiply the numbers, 
 **divide the numbers.
 **The program should then print the numbers with the chosen
 **operation and the solution. 
 */

#include <iostream>
#include <sstream>

int main()
{
  std::string loc_input{""};
  char loc_operator;
  float loc_in1{0.0}, loc_in2{0.0};

  std::cout<<"Enter two numbers:\n";

  getline(std::cin, loc_input);
  std::stringstream(loc_input) >> loc_in1;

  getline(std::cin, loc_input);
  std::stringstream(loc_input) >> loc_in2;

  std::cout<<"Enter the operation '+','-','*','/':\n";
  getline(std::cin, loc_input);
  std::stringstream(loc_input) >> loc_operator;

  switch(loc_operator)
  {
    case '+':
      {
        std::cout << loc_in1
          << " + "
          << loc_in2
          << " = "
          << loc_in1 + loc_in2
          << "\n";
      }break;
    case '-':
      {
        std::cout << loc_in1
          << " - "
          << loc_in2
          << " = "
          << loc_in1 - loc_in2
          << "\n";
      }break;
    case '*':
      {
        std::cout << loc_in1
          << " * "
          << loc_in2
          << " = "
          << loc_in1 * loc_in2
          << "\n";
      }break;
    case '/':
      {
        if(0.0 < loc_in2 || loc_in2 > 0.0)
        {
          std::cout << loc_in1
            << " / "
            << loc_in2
            << " = "
            << loc_in1 / loc_in2
            << "\n";                    }
        else
        {
          std::cout << loc_in1
            << " / "
            << loc_in2
            << " is not defined "
            << "\n";
        }
      }break;
    default:
      {
        std::cout << "bad operation \n";
      }break;
  }
  return 0;
}

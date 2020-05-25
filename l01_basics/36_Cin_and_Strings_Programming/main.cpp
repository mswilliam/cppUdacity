/*Goal: practice std::cin for strings
**Write a program that prompts two users for their
**name, address, and phone number. 
**Print the information to the console in the following format:
**name
**\/t\/t address
**\/t\/tphone number
*/

#include <iostream>
#include <string>

int main(){
  std::string loc_name{}, loc_address{}, loc_phone_number{};

  std::cout << "Enter your name \n";
  std::getline(std::cin, loc_name);

  std::cout << "Enter your address \n";
  std::getline(std::cin, loc_address);

  std::cout << "Enter your phone number \n";
  std::getline(std::cin, loc_phone_number);

  std::cout << loc_name << "\n"  \
    << "\t\t" << loc_address << "\n"  \
    << "\t\t" << loc_phone_number << "\n";
  return 0;
}

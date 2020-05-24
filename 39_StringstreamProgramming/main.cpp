/*Goal: practice using stringstream*/
/*Goal: practice getting string inputs and 
 **converting them to numeric variables using
 **stringstream.
 **
 **Prompt the user for the length of a room. 
 **Then prompt for the width of the room.
 **Print out the area of the room. 
 */

#include <iostream>
#include <sstream>

int main(){
  std::string loc_input{};
  float loc_room_length{0}, loc_room_width{0};

  std::cout << "Enter the length of a room\n";
  getline(std::cin, loc_input);
  std::stringstream(loc_input)>>loc_room_length;


  std::cout << "Enter the width of the room.";
  getline(std::cin, loc_input);
  std::stringstream(loc_input)>>loc_room_width;

  std::cout << "The area of the room is : " \
    << loc_room_length * loc_room_width;
    
  return 0;
}

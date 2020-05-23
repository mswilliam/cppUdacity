/*GOAL: Practice writing to the console and learn 
**the variables types available in C++
**Print the sizes of each variable to the console.
**Print them in the following order:
**int, short, long, char, float, double, bool
**
**Use the command sizeof(variable type) ie: sizeof(int)
*/

#include <iostream>

int main(){
  
  std::cout <<        \
    "size of int " << \
    sizeof(int) <<    \
    std::endl;

  std::cout <<        \
    "size of short " << \
    sizeof(short) <<    \
    std::endl;

  std::cout <<        \
    "size of long " << \
    sizeof(long) <<    \
    std::endl;

  std::cout <<        \
    "size of char " << \
    sizeof(char) <<    \
    std::endl;

  std::cout <<        \
    "size of float " << \
    sizeof(float) <<    \
    std::endl;

  std::cout <<        \
    "size of int " << \
    sizeof(int) <<    \
    std::endl;

  std::cout <<        \
    "size of double " << \
    sizeof(double) <<    \
    std::endl;

  std::cout <<        \
    "size of bool " << \
    sizeof(bool) <<    \
    std::endl;
}


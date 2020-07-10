/*!
 *  \file main.cpp
 *  \brief    Goal: Test the operations implementation
 *
 *  \details  call operations functions
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-07
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#include <iostream>
#include "../components/gameboard/include/gameboard.h"

int main() {
  gameboard::Gameboard game1;
  game1.setGameSpace(0, 0, 'x');
  game1.setGameSpace(0, 1, 'x');
  game1.setGameSpace(0, 2, 'x');
  game1.setGameSpace(0, 3, 'y');
  game1.setGameSpace(1, 0, 'x');
  game1.setGameSpace(2, 0, 'x');
  game1.setGameSpace(3, 0, 'x');
  game1.setGameSpace(3, 1, 'x');
  game1.setGameSpace(3, 2, 'x');
  game1.setGameSpace(3, 3, 'x');

  if (game1.fourInRow() == 1) {
    std::cout << "X got four in a row! \n\n";
  } else {
    std::cout << "X did not get four in a row :(\n\n";
  }
  game1.printInfo();
  return 0;
}

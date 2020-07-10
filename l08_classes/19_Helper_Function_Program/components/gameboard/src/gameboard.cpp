/*! 
 *  \copyright  GNU Public License.            
 *
 *  \file       gameboard.cpp
 *
 *  \brief      Goal: This is the Gemeboad class
 *
 *  \details    This class privide some manipulation feature for the gameboard
 *
 *  \author     MANGOUA SOFACK William
 *
 *  \version    1.0
 *
 *  \date       Thu Jul 9 14:26:29 CEST 2020
 *
 *
 *
 **/

#include "../include/gameboard.h"

namespace gameboard {
  // namespace gameboard


  Gameboard::Gameboard() : \
    game_space_ {\
      {'-', '-', '-', '-'}, \
      {'-', '-', '-', '-'}, \
      {'-', '-', '-', '-'}, \
      {'-', '-', '-', '-'} \
    } {
    }

  Gameboard::~Gameboard() {
  }

  void Gameboard::setGameSpace(\
      uint8_t arg_row, \
      uint8_t arg_column, \
      int8_t arg_value \
      ) {
    if (arg_row < kGameSpaceSize && arg_column < kGameSpaceSize) {
      game_space_[arg_row][arg_column] = arg_value;
    }
  }

  int8_t Gameboard::getGameSpace( \
      uint8_t arg_row, \
      uint8_t arg_column \
      ) {
    return 0;  // TODO(me)
  }

  bool Gameboard::fourInRow() {
    return true;  // TODO(me)
  }

  void Gameboard::printInfo() {
    // TODO(me)
  }

}  // namespace gameboard


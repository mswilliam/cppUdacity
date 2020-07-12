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
#include <iostream>

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
    int8_t loc_result {'*'};
    if (arg_row < kGameSpaceSize && \
        arg_column < kGameSpaceSize) {
      loc_result = game_space_[arg_row][arg_column];
    }
    return loc_result;
  }

  bool Gameboard::fourInRow() {
    bool loc_is_found {false};

    uint8_t loc_row_index {0};
    uint8_t loc_column_index {0};

    while (false == loc_is_found && \
        loc_row_index < kGameSpaceSize) {
      uint8_t loc_nb_x_in_row {0};
      while (false == loc_is_found && \
          loc_column_index < kGameSpaceSize) {
        if ('x' == \
            game_space_[loc_row_index][loc_column_index]) {
          ++loc_nb_x_in_row;
          if (loc_nb_x_in_row >= kGameSpaceSize) {
            loc_is_found = true;
          }
        }
        ++loc_column_index;
      }
      ++loc_row_index;
      loc_column_index = 0;
    }
    return loc_is_found;
  }

  void Gameboard::printInfo() {
    for (uint8_t loc_row_index = 0; \
        loc_row_index < kGameSpaceSize; \
        ++loc_row_index) {
      for (uint8_t loc_column_index = 0; \
          loc_column_index < kGameSpaceSize; \
          ++loc_column_index) {
        printf("%c", game_space_[loc_row_index][loc_column_index]);
      }
      printf("\n");
    }
  }

}  // namespace gameboard


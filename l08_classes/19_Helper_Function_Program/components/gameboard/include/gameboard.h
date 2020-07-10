/*!             
 *  \copyright  GNU Public License.
 *  \file       gameboard.h
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

#ifndef __GAMEBOARD_
#define __GAMEBOARD_

#include <cstdint>

namespace gameboard {
  // namespace gameboard

  const uint8_t kGameSpaceSize = 4;

  /* A class Gameboard class*/
  class Gameboard {
   public:
      /*! \fn Gameboard() 
       *  \brief The constructor sets each value of gameSpace to the char value '-'
       */
      Gameboard();

      ~Gameboard();

      /*! \fn void setGameSpace(uint8_t arg_row, uint8_t arg_column, int8_t arg_value)
       *  \brief Each position to be set with a single char.
       *  \param[in] arg_row the selected row.
       *  \param[in] arg_column the selected column.
       *  \param[in] arg_value the char to write.
       */
      void setGameSpace(uint8_t arg_row, uint8_t arg_column, int8_t arg_value);

      /*! \fn int8_t getGameSpace(uint8_t arg_row, uint8_t arg_column)
       *  \brief each position can be read individually
       *  \param[in] arg_row the selected row.
       *  \param[in] arg_column the selected column.
       *  \return a character at row arg_row and column arg_col
       */
      int8_t getGameSpace(uint8_t arg_row, uint8_t arg_column);

      /*! \fn bool fourInRow()
       *  \brief checks every row, looking for four 'x's. When it finds four x's in the same row, it returns a true, otherwise it returns a false.
       *  \return a boolean : true or false
       */
      bool fourInRow();

      /*! \fn void printInfo()
       *  \brief print gameSpace as a 4x4 matrix
       */
      void printInfo();

      // Forbid the copy operations
      Gameboard(const Gameboard &) = delete;
      Gameboard& operator=(const Gameboard &) = delete;

      // Forbid the move operations
      Gameboard(Gameboard&&) = delete;
      Gameboard& operator=(Gameboard&&) = delete;

   private:
      int8_t game_space_[kGameSpaceSize][kGameSpaceSize];
  };

  /*! \class Gameboard.h
   * \brief This is Gameboard class
   *
   * Gameboard has a private member 'game_space_[4][4]' 
   * that is a 4x4 array that accepts a char for each of 
   * the 16 positions.
   * The class has four public members 
   * that are functions and a constructor
   */

}  // namespace gameboard
#endif  // __GAMEBOARD_


/*!
 *  \file main.cpp
 *  \brief    Goal: Test the operations implementation
 *
 *  \details  call operations functions
 *
 *  \author   MANGOUA SOFACK William
 *  \version  1.0
 *  \date     2020-06-14
 *  \copyright GNU Public License.
 *
 *
 *
 **/

#include <cstdio>
#include <cstdint>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include "CppUTest/TestHarness.h"
#include "../include/gameboard.h"

TEST_GROUP (SetAndGetGameSpaceGroup) {

  //  Define data accessible to the test group members here.

  // This global variable is used for all the tests in this group
  gameboard::Gameboard gl_gameboard;

  void setup () {
    //  initialization steps are executed before each TEST
    for (uint8_t loc_row_index = 0; \
        loc_row_index < gameboard::kGameSpaceSize; \
        ++loc_row_index) {
      for (uint8_t loc_col_index = 0; \
          loc_col_index < gameboard::kGameSpaceSize; \
          ++loc_col_index) {
        gl_gameboard.setGameSpace (loc_row_index, loc_col_index, '-');
      }
    }
  }

  void tearDown () {
    //  ceanup steps are excuted after each TEST
  }
};

TEST_GROUP (FourInRowGameSpaceGroup) {

  //  Define data accessible to the test group members here.

  // This global variable is used for all the tests in this group
  gameboard::Gameboard gl_gameboard;

  void setup () {
    //  initialization steps are executed before each TEST
    for (uint8_t loc_row_index = 0; \
        loc_row_index < gameboard::kGameSpaceSize; \
        ++loc_row_index) {
      for (uint8_t loc_col_index = 0; \
          loc_col_index < gameboard::kGameSpaceSize; \
          ++loc_col_index) {
        gl_gameboard.setGameSpace(loc_row_index, loc_col_index, '-');
      }
    }
  }

  void tearDown () {
    //  ceanup steps are excuted after each TEST
  }
};

TEST_GROUP (PrintInfoGameSpaceGroup) {

  //  Define data accessible to the test group members here.

  // This global variable is used for all the tests in this group
  gameboard::Gameboard gl_gameboard;

  void setup () {
    //  initialization steps are executed before each TEST
    for (uint8_t loc_row_index = 0; \
        loc_row_index < gameboard::kGameSpaceSize; \
        ++loc_row_index) {
      for (uint8_t loc_col_index = 0; \
          loc_col_index < gameboard::kGameSpaceSize; \
          ++loc_col_index) {
        gl_gameboard.setGameSpace(loc_row_index, loc_col_index, '-');
      }
    }
  }

  void tearDown () {
    //  ceanup steps are excuted after each TEST
    if (0 == std::remove ("output_redirection_file.txt")) {
      printf ("File removed succesfully \n");
    } else {
      printf ("File connot be removed succesfully \n");
    }
    std::remove("output_redirection_file.txt");
  }
};

TEST (PrintInfoGameSpaceGroup, emptyBoard) {
  struct stat loc_statistics;

  // Save the position of the current standard output
  fpos_t loc_stdout_position;
  fgetpos (stdout, &loc_stdout_position);
  int fd = dup (fileno(stdout));

  // redirect the stdout
  freopen ("output_redirection_file.txt", "w", stdout);

  // call printf
  gl_gameboard.printInfo ();

  // Flush stdout so any buffered messages are delivere
  fflush (stdout);

  // Close file ans restore standard output to stdout, which should be the terminal
  dup2 (fd, fileno (stdout));
  close (fd);
  clearerr (stdout);
  fsetpos (stdout, &loc_stdout_position);

  // assert checking nb characters
  stat ("output_redirection_file.txt", &loc_statistics);
  CHECK_EQUAL (gameboard::kGameSpaceSize * gameboard::kGameSpaceSize, loc_statistics.st_size);

  // assert checking content
  std::ifstream loc_redirection_file ("output_redirection_file.txt");
  if (loc_redirection_file.is_open ()) {
    std::string loc_line;
    while (getline (loc_redirection_file, loc_line)) {
      STRCMP_EQUAL ("----", loc_line.c_str ());
    }
    loc_redirection_file.close ();
  } else {
    FAIL ("Unable to open file for reading \n");
  }
}

TEST (FourInRowGameSpaceGroup, emptyBoard) {
  CHECK_FALSE (gl_gameboard.fourInRow ());
}

TEST (FourInRowGameSpaceGroup, oneXBoard) {
  for (uint8_t loc_index = 0; \
      loc_index < gameboard::kGameSpaceSize; \
      ++loc_index) {
    gl_gameboard.setGameSpace (loc_index, loc_index, 'x');
  }
  CHECK_FALSE (gl_gameboard.fourInRow ());
}

TEST (FourInRowGameSpaceGroup, twoXBoard) {
  for (uint8_t loc_index = 0; \
      loc_index < gameboard::kGameSpaceSize - 1; \
      ++loc_index) {
    gl_gameboard.setGameSpace (loc_index, loc_index, 'x');
    gl_gameboard.setGameSpace (loc_index, loc_index + 1, 'x');
  }
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 1, 'x');
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 2, 'x');
  CHECK_FALSE (gl_gameboard.fourInRow ());
}

TEST (FourInRowGameSpaceGroup, threeXBoard) {
  for (uint8_t loc_index = 0; \
      loc_index < gameboard::kGameSpaceSize - 2; \
      ++loc_index) {
    gl_gameboard.setGameSpace (loc_index, loc_index, 'x');
    gl_gameboard.setGameSpace (loc_index, loc_index + 1, 'x');
    gl_gameboard.setGameSpace (loc_index, loc_index + 2, 'x');
  }
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 1, 'x');
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 2, 'x');
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 3, 'x');
  CHECK_FALSE (gl_gameboard.fourInRow ());
}

TEST (FourInRowGameSpaceGroup, fourXBoard) {
  for (uint8_t loc_index = 0; \
      loc_index < gameboard::kGameSpaceSize - 2; \
      ++loc_index) {
    gl_gameboard.setGameSpace (loc_index, loc_index, 'x');
    gl_gameboard.setGameSpace (loc_index, loc_index + 1, 'x');
    gl_gameboard.setGameSpace (loc_index, loc_index + 2, 'x');
  }
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 1, 'x');
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 2, 'x');
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 3, 'x');
  gl_gameboard.setGameSpace (gameboard::kGameSpaceSize - 1, \
      gameboard::kGameSpaceSize - 4, 'x');
  CHECK (gl_gameboard.fourInRow ());
}

TEST (SetAndGetGameSpaceGroup, setOneCharacter) {
  uint8_t loc_row_upate_index {0};
  uint8_t loc_col_update_index {0};
  int8_t loc_updated_value {'a'};

  gameboard::Gameboard loc_gameboard;

  // copy the gameboard befor modification
  for (uint8_t loc_row_index = 0; \
      loc_row_index < gameboard::kGameSpaceSize; \
      ++loc_row_index) {
    for (uint8_t loc_col_index = 0; \
        loc_col_index < gameboard::kGameSpaceSize; \
        ++loc_col_index) {
      loc_gameboard.setGameSpace(loc_row_index, \
          loc_col_index, \
          gl_gameboard.getGameSpace (loc_row_index, loc_col_index));
    }
  }

  // set the value
  loc_gameboard.setGameSpace (loc_row_upate_index, \
      loc_col_update_index, \
      loc_updated_value);

  // test
  for (uint8_t loc_row_index = 0; \
      loc_row_index < gameboard::kGameSpaceSize; \
      ++loc_row_index) {
    for (uint8_t loc_col_index = 0; \
        loc_col_index < gameboard::kGameSpaceSize; \
        ++loc_col_index) {
      if (loc_row_index == loc_row_upate_index && \
          loc_col_index == loc_col_update_index) {
        CHECK (loc_gameboard.getGameSpace( \
              loc_row_index, loc_col_index) == \
            gl_gameboard.getGameSpace(loc_row_index, \
              loc_col_index));
      } else {
        CHECK (loc_updated_value == \
            gl_gameboard.getGameSpace(loc_row_index, \
              loc_col_index));
      }
      loc_gameboard.setGameSpace (loc_row_index, \
          loc_col_index, \
          gl_gameboard.getGameSpace (loc_row_index, loc_col_index));
    }
  }
}


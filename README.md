# div
A Divination Machine
Version: Alpha 1.2.0
March 31st, 2023
Copyright 2022-2023 act
https://github.com/act17/div

# Purpose
  The purpose of this program is as a novelty. It provides divination by way of randomly selecting tarot cards.

# Compiling
  To compile the program, simply run ``make`` to compile the program. By default, the Makefile uses GCC to compile the program.

# Use
  To use the program, simply run it by running ``./div`` with a query following it. By default, it will return three cards based on your query.

  The format, if you need help, is ``./div "<query>" <options>``. ``"<query>"`` obviously being the query you want to ask. You must bookend the query with proper quotation marks (``"``) in order for it to be parsed correctly.

  As for options, the current version has the following:
  ``--help`` - This prints out a message that details the commands, and the format for using the program.
  ``-c _`` - This changes the number of cards you would like to be returned to you. ``_`` should be replaced with an integer equal to the value of the cards you'd like returned.
  ``-u`` - This forces all cards to be upright.

# Todo
  By Beta 1.0.0, the following should be done:

  - The addition of an "Accuracy" check that measures the time from the current system date to the next Solstice/Equinox, and from the current date until the next Full Moon.
  - Fix any bugs or similar that may become apparent post-release.

# Changelog

  *Alpha 1.2.0 (March 31st, 2023)*
  - Altered ``./sources/tarottools/tarotprint.c`` to no longer use a singular seed to generate reversed cards; preventing garunteed reverses.

  *Alpha 1.1.0 (March 5th, 2023)*
  - Altered ``./sources/tarottools/tarotgen.c`` to not generate the same seed upon the first card.

  *Alpha 1.0.0 (December 21st, 2022)*
  - Added ``main.c``, which takes the user input and subsequently calls macros to calculate and print.
  - Added the directory ``/tarottools/``, which includes various files used by the program. The directory has the following files, which were added:
    - ``tarottools.h`` - The header file that includes all the functions within the directory of ``/tarottools/``.
    - ``querytonumber.c`` - Includes the function ``unsigned int QueryToNumberConverter(char *Query)``. It takes the string, ``*Query``, and adds each character's value to an unsigned integer which is then returned.
    - ``tarotgen.c`` - Includes the function ``void TarotGenerator(int *Cards, int *Decks, unsigned int QueryNumeric, int *Options)``. Uses ``QueryNumeric`` to alter a time-based seed which randomly generates a number through 0 to 4, which is written to ``*Decks``. Then, depending on the value of ``*Decks``, a number either between 1 and 14, or a number between 0 and 21 is randomly generated and written to ``*Cards``. This repeats for as long as a value in ``*Options`` determines.
    - ``tarotprint.c`` - Includes the function ``void TarotPrint(int *Cards, int *Decks, int *Options)``. This will print a line which contains the card specified by an integer within ``*Decks`` and ``*Cards``. This repeats for as long as a value in ``*Options`` determines.

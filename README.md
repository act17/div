# div
A Divination Machine

Version: Alpha 1.4.0  ||  2023/04/10

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
  ``-c`` - This changes the number of cards you would like to be returned to you.
  ``-g`` - Changes the form of Gematria used.


# Todo
  By Beta 1.0.0, the following should be done:

  - The addition of an "Accuracy" check that measures the time from the current system date to the next Solstice/Equinox, and from the current date until the next Full Moon.
  - Fix any bugs or similar that may become apparent post-release.

# Changelog

  *Alpha 1.4.0 (April 10th, 2023)*
  - Altered ``./Makefile`` to now include a new target; ``debug``. It compiles the program with the ``-g`` flag.
  - Altered ``./src/main.c`` to no longer handle the parsing of arguments, and moved ``HelpPrint()`` to another file. As a result, the function is now far more condensed.
  - Added new file ``./src/argparse.c``. It includes the function ``char* ArgumentParser(char** Arguments, int* Options)``. It performs the argument parsing that used to be handled in ``int main()``. ``HelpPrint()`` has also been moved to this file.
  - Altered ``./src/tarot/gematria.c`` to now correct Gematria flaws. I was an idiot and failed to initialize the several usages of Integers to zero; leading to the obvious errors. Code has also been condensed for readability.
  - Moved ``./src/tarot/tarot.h`` to ``./src/``, and renamed it to ``div.h``. The contents of the files have now been altered to reflect this change, and has added ``ArgumentParser()``.


  *Alpha 1.3.0 (April 10th, 2023)*
  - Changed directory ``./sources/`` to ``./src/``.
    - Changed directory ``./src/tarottools/`` to ``./src/tarot/``.
    - Changed file name ``./src/tarot/tarottools.h`` to ``./src/tarot/tarot.h``.
  - Added file ``./src/tarot/gematria.c``. It includes the functions ``int Gematria(char *Query, int Type)``, ``int ASCIIGematria(char *Query)``, and ``int EnglishGematria(char *Query, int Type)``.
    - These basically handle how the program converts a query into a number. Previously it just used the ASCII character of each character in the Query. Although that's still possible by using the ``-g`` parameter, by-default it uses the English method.
  - Changed how ``./src/main.c`` handles parsing arguments. It now uses a ``switch()`` statement.
  - (Almost all) references to options - e.g. the former use of ``int CardNumber`` in ``int main()`` have now been simply condensed into ``int *Options``.
  - The argument ``-u`` has been depricated.
  - The argument ``-g`` has now been added; it changes the type of Gematria used.
  - ``main.c`` now includes the function ``void HelpPrint()``. It simply prints the help message.
  - Altered ``./Makefile`` heavily. It's entirely revamped for ease of future use, and now includes formatting options via ``astyle``.


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

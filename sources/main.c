#include "tarottools/tarottools.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  // Calling the operators nessicary for program function:
  char *Query;
  unsigned int QueryNumeric;

  // Calling the operators used for options:
  unsigned int CardNumber = 3;
  int ReversedCards = 0;

  // Calling the array-array (?) that's used to transport the options:
  int Options[2];

  // Parsing the arguments:
  // This block occurs in the case that there's no arguments; including no
  // question.
  if (argv[1] == NULL) {
    printf("\nError! No arguments have been passed.");
    printf("\nPlease pass the --help argument if you need assistance.\n");
    return 1;
  }

  // This loop will run through all the arguments given otherwise.
  for (int i = 1; argv[i] != NULL; i++) {

    // --help - Printing syntax and a list of commands.
    if (strcmp(argv[i], "--help") == 0) {

      printf("\nFormat: div <arguments> ''<query>''\n");
      printf("\nList of arguments:");
      printf("\n--help      Prints this list. Breaks the usage of any other "
             "command.");
      printf("\n-c          Increases the number of cards drawn. Must be a "
             "positive integer. (Default: 3)");
      printf("\n-u          Every card will be upright. No parameters besides "
             "'-u' are needed. (Default: 0/Reversed cards enabled.)");
      printf("\n");
      return 1;
    }

    // -c - Setting the number of cards to be drawn.
    if (strcmp(argv[i], "-c") == 0) {
      i++;
      CardNumber = atoi(argv[i]);
    }

    // -u - Forcing all cards to be upright.
    if (strcmp(argv[i], "-u") == 0)
      ReversedCards = 1;

    // The failsafe block in the case that an illegal argument is passed.
    else if (argv[i][0] == '-') {
      printf("\nError! Unknown command entered!");
      printf("\nUnknown command: -");

      for (int j = 1; argv[i][j] != '\0'; j++)
        printf("%c", argv[i][j]);

      printf("\nRun div --help for a list of commands and proper syntax.");
      return 1;

    }

    // Otherwise, the question is then entered.
    else
      Query = argv[i];
  }

  // Then we convert our Query to an unsinged integer:
  QueryNumeric = QueryToNumberConverter(Query);

  // Placing our options into an array of arrays for the sake of transportation:
  Options[0] = CardNumber;
  Options[1] = ReversedCards;

  // Next, we call the arrays that will used for card storage:
  int Cards[CardNumber];
  int Decks[CardNumber];

  // Then generating our cards:
  TarotGenerator(Cards, Decks, QueryNumeric, Options);

  // Then we print the cards:
  TarotPrint(Cards, Decks, Options);

  return 0;
}

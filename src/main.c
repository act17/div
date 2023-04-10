#include "tarot/tarot.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// To be altered each time there's an increase of Gematria types.
#define NUMBER_OF_GEMATRIA 1

// Prints the --help message.
void HelpPrint() {
  printf("\nFormat: div <arguments> ''<query>''\n");
  printf("\nList of arguments:");
  printf("\n--help      Prints this list. Breaks the usage of any other "
         "command.");
  printf("\n-c          Increases the number of cards drawn. Must be a "
         "positive integer. (Default: 3)");
  printf("\n-g	    Sets the type of Gematria used.\n0 = English (Default) | 1 = ASCII");
  printf("\n");
  return;
}

int main(int argc, char **argv) {

  // Calling the operators nessicary for program function:
  char *Query;
  unsigned int QueryNumeric;

  // Calling the array-array (?) that's used to transport the options:
  int Options[3];
  Options[0] = 3;  // This controls the number of cards.
  Options[1] = 0;  // This controls the Gematria used.

  // Calling the operator that's used to store info relating to parameters.
  int ArgBuffer;

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

    // In the case we need to print the help message:
    if (strcmp(argv[i], "--help") == 0) {
      HelpPrint();
      return 1;
    }

    // We check to see if we're trying to pass an argument with '-' and there's an argument ahead of it.
    if (argv[i][0] == '-' && argv[i + 1] != NULL) {
      // If we can confirm an argument is trying to be passed, we use a switch statement
      // to see what to do next.
      switch (argv[i][1]) {

      // We change the number of cards with '-c'.
      case 'c':
        i++;
        ArgBuffer = atoi(argv[i]);
        if (ArgBuffer < 1)
          printf("\nError! Argument passed after '-c' is illegal!\n");
        else
          Options[0] = ArgBuffer;
        break;

      // We change the use of Gematria with '-g'.
      case 'g':
        i++;
        ArgBuffer = atoi(argv[i]);
        if (ArgBuffer > NUMBER_OF_GEMATRIA || ArgBuffer < 0)
          printf("\nError! Argument passed after '-g' is illegal!\n");
        else
          Options[2] = ArgBuffer;
        break;

      // Otherwise...
      default:
        printf("\nError! Argument #%d is not filled in/invalid!\n", i);
        break;
      }
    }

    // In the case that we are not passing an argument, however, we use it as the query.
    else
      Query = argv[i];
  }

  // We then call the arrays used for the Cards and their Decks.
  int Cards[Options[0]];
  int Decks[Options[0]];

  // We then convert the query into a number, generate cards, and print.
  QueryNumeric = Gematria(Query, Options[1]);
  TarotGenerator(Cards, Decks, QueryNumeric, Options);
  TarotPrint(Cards, Decks, Options);

  return 0;
}

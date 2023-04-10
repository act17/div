#include "div.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {

  // Calling the array that's used to control the options.
  int Options[2];
  Options[0] = 3;  // This controls the number of cards.
  Options[1] = 0;  // This controls the Gematria used.

  // This block occurs in the case that there's no arguments; including no
  // question.
  if (argv[1] == NULL) {
    printf("\nError! No arguments have been passed.");
    printf("\nPlease pass the --help argument if you need assistance.\n");
    return 1;
  }

  // Then we parse the arguments and get the query.
  char* Query = ArgumentParser(argv, Options);

  // We then call the arrays used for the Cards and their Decks.
  int Cards[Options[0]];
  int Decks[Options[0]];

  // We then convert the query into a number.
  int QueryNumeric = Gematria(Query, Options[1]);

  // Then we generate the cards, and print.
  TarotGenerator(Cards, Decks, QueryNumeric, Options);
  TarotPrint(Cards, Decks, Options);

  return 0;
}

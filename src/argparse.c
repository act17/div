#include <stdlib.h>
#include <stdio.h>

// To be updated per each increase of Gematria type.
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

// This function parses the arguments passed into the program, and alters
// the Options array to match. It also returns the query.
char* ArgumentParser(char** Arguments, int* Options) {

  char* Query;
  int ArgBuffer;

  // This loop will run through all the arguments given otherwise.
  for (int i = 1; Arguments[i] != NULL; i++) {

    // We check to see if we're trying to pass an argument with '-' and there's an argument ahead of it.
    if (Arguments[i][0] == '-' && Arguments[i + 1] != NULL) {
      // If we can confirm an argument is trying to be passed, we use a switch statement
      // to see what to do next.
      switch (Arguments[i][1]) {

      // We change the number of cards with '-c'.
      case 'c':
        i++;
        ArgBuffer = atoi(Arguments[i]);
        if (ArgBuffer < 1)
          printf("\nError! Argument passed after '-c' is illegal!\n");
        else
          Options[0] = ArgBuffer;
        break;

      // We change the use of Gematria with '-g'.
      case 'g':
        i++;
        ArgBuffer = atoi(Arguments[i]);
        if (ArgBuffer > NUMBER_OF_GEMATRIA || ArgBuffer < 0)
          printf("\nError! Argument passed after '-g' is illegal!\n");
        else
          Options[1] = ArgBuffer;
        break;

      // Otherwise...
      default:
        printf("\nError! Argument #%d is not filled in/invalid!\n", i);
        break;
      }
    }

    // In the case that we are not passing an argument, however, we use it as the query.
    else
      Query = Arguments[i];
  }

  return Query;
}

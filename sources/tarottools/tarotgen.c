#include <stdlib.h>
#include <time.h>

void TarotGenerator(int *Cards, int *Decks, unsigned int QueryNumeric,
                    int *Options) {

  // First we parse the options:
  int CardNumber = Options[0];

  // Then we start the loop to enter each entry.
  for (int i = 0; i < CardNumber; i++) {

    // Then we set the random seed - equal to the time,
    // multiplied by the Query's Numeric value, which in
    // itself is multiplied by i.
    srand(time(0) * (QueryNumeric * (i + 1)));

    // First we see the deck.
    // If zero, it's the major archana.
    Decks[i] = rand() % 5;

    // In that case, we randomly generate a number
    // from 0 to 21.
    if (Decks[i] == 0)
      Cards[i] = rand() % 22;

    // Otherwise we generate a card from 1 through 14.
    else
      Cards[i] = (rand() % 14) + 1;
  }
}

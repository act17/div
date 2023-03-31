#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char MajorArchana[22][1024] = {"The Fool",
                               "The Magician",
                               "The High Priestess",
                               "The Empress",
                               "The Emperor",
                               "The Hierophant",
                               "The Lovers",
                               "The Chariot",
                               "Justice",
                               "The Hermit",
                               "The Wheel of Fortune",
                               "Strength",
                               "The Hanged Man",
                               "Death",
                               "Temperance",
                               "The Devil",
                               "The Tower",
                               "The Star",
                               "The Moon",
                               "The Sun",
                               "Judgement",
                               "The World"};

void TarotPrint(int *Cards, int *Decks, int *Options) {

  // First we parse the options.
  int CardNumber = Options[0];
  int ForceUpright = Options[1];

  for (int i = 0; i < CardNumber; i++) {

    // First we print the card we're on:
    printf("\nCard %d:  ", i + 1);

    // Then, if the deck isn't equal to zero, we do the following routine:
    if (Decks[i] != 0) {

      // Use a switch statement to check if the card's number is "Special"
      // and has a name (1, 14, 13, 12, and 11)
      // Otherwise, print the number.
      switch (Cards[i]) {

      case 1:
        printf("Ace ");
        break;

      case 14:
        printf("King  ");
        break;

      case 13:
        printf("Queen ");
        break;

      case 12:
        printf("Knight  ");
        break;

      case 11:
        printf("Page  ");
        break;

      default:
        printf("%d  ", Cards[i]);
        break;
      }

      // Use another switch statement to print the deck.
      switch (Decks[i]) {

      case 1:
        printf("of Wands.");
        break;

      case 2:
        printf("of Cups.");
        break;

      case 3:
        printf("of Coins.");
        break;

      case 4:
        printf("of Swords.");
        break;
      }
    }

    // In the case that we however, do not have a minor archana card,
    // then we refer to printing the name of the corresponding Major Archana
    // card.
    else
      printf("%s", MajorArchana[Cards[i]]);

    // The last thing that's done, is if we aren't forcing all cards to be
    // upright then we flip a coint to see if we'll reverse the card in print:
    if (ForceUpright == 0) {

      srand(time(0) * (i + 1));

      if (rand() % 7 == 1)
        printf("  (Reversed)");
    }
  }

  printf("\n");
  return;
}

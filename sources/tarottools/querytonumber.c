#include <stdlib.h>

unsigned int QueryToNumberConverter(char *Query) {

  unsigned int Number;

  for (int i = 0; Query[i] != '\0'; i++)
    Number = Number + Query[i];

  return Number;
}

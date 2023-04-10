#include <stdlib.h>

int EnglishGematria(char* Query) {
  int Number;
  int TempValue;

  for (int i = 0; Query[i] != '\0'; i++) {
    TempValue = 0;

    if (Query[i] >= 65 && Query[i] <= 90) {
      TempValue = Query[i] - 64;
    }
    if (Query[i] >= 97 && Query[i] <= 122) {
      TempValue = Query[i] - 96;
    }

    Number = Number + (TempValue * 6);

  }

  return Number;
}

int ASCIIGematria(char* Query) {

  unsigned int Number;

  for (int i = 0; Query[i] != '\0'; i++)
    Number = Number + Query[i];

  return Number;
}

int Gematria(char *Query, int Type) {

  int Number;
  switch (Type) {
  case 0:
    Number = EnglishGematria(Query);
    break;
  case 1:
    Number = ASCIIGematria(Query);
    break;
  default:
    break;
  }

  return Number;
}

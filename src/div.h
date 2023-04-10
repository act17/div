#ifndef _DIV_H
#define _DIV_H

char* ArgumentParser(char** Arguments, int* Options);

int Gematria(char* Query, int Type);
void TarotGenerator(int* Cards, int* Decks, unsigned int Question, int* Options);
void TarotPrint(int* Cards, int* Decks, int* Options);

#endif

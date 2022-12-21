#ifndef _TAROTTOOLS_H
#define _TAROTTOOLS_H

int QueryToNumberConverter(char* Query);
void TarotGenerator(int* Cards, int* Decks, unsigned int Question, int* Options);
void TarotPrint(int* Cards, int* Decks, int* Options);

#endif

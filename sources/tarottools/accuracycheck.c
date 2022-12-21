#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void AccuracyCheck(){

  // First we get the current date:
  time_t t;
  t = time(0);
  struct tm tm = *localtime(&t);

  // This number will go up from 1 to 365 depending on the date.
  int DaysPassedSinceNewYear = 0;

  // This number will be used to calculate the days until the next
  // major solar event (E.g. Equinoxes or Solstices).
  int DaysUntilSolar = 0;
  
  // This struct permits the for loop below to add to the total
  // days passed since the beginning of this year accurately.
  // December is not included.
  int DaysPerMonth[11] = {31,28,31,30,31,30,31,31,30,31,30};
  
  // This will go for each month that's passed.
  for(int i = 0; i < (tm.tm_mon + 1); i++)
    DaysPassedSinceNewYear = DaysPassedSinceNewYear + DaysPerMonth[i];
  
  // The next step is simply adding the date within the current month
  // to the total.
  DaysPassedSinceNewYear = DaysPassedSinceNewYear + tm.tm_mday;  

  // In the case that our day takes place before the Spring Equinox
  // but after the Winter Solstice:
  if(DaysPassedSinceNewYear < 80 || DaysPassedSinceNewYear > 356){
    
  }

  printf("%d", DaysPassedSinceNewYear);
  return;
}

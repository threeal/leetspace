#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int numRescueBoats(int* people, int peopleSize, int limit) {
  int boats = 0;

  qsort(people, peopleSize, sizeof(int), comp);

  int* peopleEnd = people + peopleSize - 1;
  while (people < peopleEnd) {
    ++boats;
    if (*people + *peopleEnd <= limit) ++people;
    --peopleEnd;
  }

  if (people == peopleEnd) ++boats;
  return boats;
}

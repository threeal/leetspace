#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  char ab[21] = {0};
  strcat(ab, a);
  strcat(ab, b);

  char ba[21] = {0};
  strcat(ba, b);
  strcat(ba, a);

  return strcmp(ba, ab);
}

char* largestNumber(int* nums, int numsSize) {
  static char buffer[1100];

  for (int i = 0; i < numsSize; ++i) {
    sprintf(buffer + i * 11, "%d", nums[i]);
  }

  qsort(buffer, numsSize, sizeof(char) * 11, compare);

  for (int i = 1; i < numsSize; ++i) {
    strcat(buffer, buffer + i * 11);
  }

  if (buffer[0] == '0') buffer[1] = 0;
  return buffer;
}

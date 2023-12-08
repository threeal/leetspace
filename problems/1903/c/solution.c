#include <string.h>

char* largestOddNumber(char* num) {
  // Iterating from the last element to find an odd digit.
  for (int i = strlen(num); i > 0; --i) {
    if ((num[i - 1] - '0') % 2 != 1) continue;
    num[i] = 0;
    return num;
  }

  // No odd digit found.
  num[0] = 0;
  return num;
}

#include <stdlib.h>
#include <string.h>

int equalSubstring(char* s, char* t, int maxCost) {
  int maxLength = 0;
  const int sSize = strlen(s);
  int left = sSize - 1;
  int right = sSize - 1;
  while (left >= 0) {
    maxCost -= abs(s[left] - t[left]);
    while (maxCost < 0) {
      maxCost += abs(s[right] - t[right]);
      --right;
    }
    if (right - left + 1 > maxLength) maxLength = right - left + 1;
    --left;
  }
  return maxLength;
}

#include <string.h>

int minimumLength(char* s) {
  int left = 0;
  int right = strlen(s) - 1;

  while (left < right) {
    if (s[left] != s[right]) break;

    const char c = s[left];
    while (s[left] == c && left <= right) ++left;
    while (s[right] == c && left <= right) --right;
  }

  return right - left + 1;
}

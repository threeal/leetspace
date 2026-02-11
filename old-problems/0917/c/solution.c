#include <stdbool.h>
#include <string.h>

static bool isLetter(char c);

char* reverseOnlyLetters(char* s) {
  const int sLen = strlen(s);
  int l = 0, r = sLen - 1;
  while (l < r) {
    while (l < r && !isLetter(s[l])) ++l;
    if (l >= r) break;

    while (l < r && !isLetter(s[r])) --r;
    if (l >= r) break;

    const char temp = s[l];
    s[l] = s[r];
    s[r] = temp;
    ++l, --r;
  }
  return s;
}

static bool isLetter(char c) {
  if (c < 'A') return false;
  if (c <= 'Z') return true;
  if (c < 'a') return false;
  if (c <= 'z') return true;
  return false;
}

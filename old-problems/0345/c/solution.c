#include <stdbool.h>
#include <string.h>

bool isVowel(char c) {
  switch (c) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
  }
  return false;
}

char* reverseVowels(char* s) {
  int right = strlen(s) - 1;
  while (right > 0 && !isVowel(s[right])) --right;

  int left = 0;
  while (left < right && !isVowel(s[left])) ++left;

  while (left < right) {
    const int temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    --right;
    while (left < right && !isVowel(s[right])) --right;

    ++left;
    while (left < right && !isVowel(s[left])) ++left;
  }

  return s;
}

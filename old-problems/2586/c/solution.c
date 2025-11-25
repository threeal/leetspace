#include <stdbool.h>
#include <string.h>

static bool isVowel(char c);

int vowelStrings(char** words, int wordsSize, int left, int right) {
  (void)wordsSize;
  int count = 0;
  for (int i = left; i <= right; ++i) {
    if (isVowel(words[i][0]) && isVowel(words[i][strlen(words[i]) - 1])) {
      ++count;
    }
  }
  return count;
}

static bool isVowel(char c) {
  switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
      return true;
  }
  return false;
}

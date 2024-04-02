#include <string.h>

char* firstPalindrome(char** words, int wordsSize) {
  for (int i = 0; i < wordsSize; ++i) {
    int l = 0;
    int r = strlen(words[i]) - 1;
    while (l < r && words[i][l] == words[i][r]) {
      ++l;
      --r;
    }
    if (l >= r) return words[i];
  }
  return "";
}

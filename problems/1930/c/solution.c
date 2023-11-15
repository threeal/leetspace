#include <stdbool.h>

int countPalindromicSubsequence(char* s) {
  char* charsIt[26][2] = {0};
  while (*s != 0) {
    int c = *s - 'a';
    if (charsIt[c][0] == 0) {
      charsIt[c][0] = charsIt[c][1] = s;
    } else {
      charsIt[c][1] = s;
    }
    ++s;
  }

  int count = 0;
  for (int i = 0; i < 26; ++i) {
    bool charsExist[26] = {false};
    for (char* ci = charsIt[i][0] + 1; ci < charsIt[i][1]; ++ci) {
      int c = *ci - 'a';
      if (charsExist[c]) continue;
      charsExist[c] = true;
      ++count;
    }
  }

  return count;
}

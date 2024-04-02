// The problem can be solved by finding the left and right pointers of each character
// and then counting the unique characters between those pointers.

#include <stdbool.h>

int countPalindromicSubsequence(char* s) {
  // Find the left and right pointers of each character.
  char* charsIt[26][2] = {0};
  while (*s != 0) {
    *s -= 'a';
    if (charsIt[*s][0] == 0) {
      charsIt[*s][0] = charsIt[*s][1] = s;
    } else {
      charsIt[*s][1] = s;
    }
    ++s;
  }

  // Count the number of unique characters between each pair of pointers.
  int count = 0;
  for (int i = 0; i < 26; ++i) {
    bool charsExist[26] = {false};
    for (char* c = charsIt[i][0] + 1; c < charsIt[i][1]; ++c) {
      if (charsExist[*c]) continue;
      charsExist[*c] = true;
      ++count;
    }
  }

  return count;
}

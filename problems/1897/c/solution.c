#include <stdbool.h>

bool makeEqual(char** words, int wordsSize) {
  int counts[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < wordsSize; ++i) {
    char* c = words[i];
    while (*c != 0) {
      ++counts[*c - 'a'];
      ++c;
    }
  }

  for (int i = 0; i < 26; ++i) {
    if (counts[i] % wordsSize != 0) return false;
  }

  return true;
}

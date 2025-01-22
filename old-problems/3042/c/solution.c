#include <string.h>

int countPrefixSuffixPairs(char** words, int wordsSize) {
  int count = 0;
  for (int i = 0; i < wordsSize; ++i) {
    const int ni = strlen(words[i]);
    for (int j = i + 1; j < wordsSize; ++j) {
      const int nj = strlen(words[j]);
      if (ni > nj) continue;
      if (strncmp(words[j], words[i], ni) != 0) continue;
      if (strncmp(words[j] + nj - ni, words[i], ni) != 0) continue;
      ++count;
    }
  }
  return count;
}

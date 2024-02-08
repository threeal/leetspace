#include <stdbool.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int*)b - *(int*)a;
}

bool closeStrings(char* word1, char* word2) {
  int word1Counts[26] = {0};
  while (*word1 != 0) {
    ++word1Counts[*word1 - 'a'];
    ++word1;
  }

  int word2Counts[26] = {0};
  while (*word2 != 0) {
    ++word2Counts[*word2 - 'a'];
    ++word2;
  }

  for (int i = 0; i < 26; ++i) {
    if ((word1Counts[i] > 0) != (word2Counts[i] > 0))
      return false;
  }

  qsort(word1Counts, 26, sizeof(int), comp);
  qsort(word2Counts, 26, sizeof(int), comp);

  for (int i = 0; i < 26; ++i) {
    if (word1Counts[i] != word2Counts[i])
      return false;
  }

  return true;
}

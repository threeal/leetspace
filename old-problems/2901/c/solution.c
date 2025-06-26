#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool validHammingDistance(char* a, int aSize, char* b);

char** getWordsInLongestSubsequence(
    char** words, int wordsSize, int* groups, int groupsSize, int* returnSize) {
  (void)groupsSize;

  int* wordLens = malloc(wordsSize * sizeof(int));
  for (int i = 0; i < wordsSize; ++i) {
    wordLens[i] = strlen(words[i]);
  }

  int* lengths = malloc(wordsSize * sizeof(int));
  int* prevs = malloc(wordsSize * sizeof(int));

  int maxI = 0;
  lengths[0] = 1;

  for (int i = 1; i < wordsSize; ++i) {
    lengths[i] = 1;
    for (int j = i; j > 0; --j) {
      if (lengths[j - 1] + 1 >= lengths[i] &&
          groups[j - 1] != groups[i] &&
          wordLens[j - 1] == wordLens[i] &&
          validHammingDistance(words[j - 1], wordLens[j - 1], words[i])) {
        lengths[i] = lengths[j - 1] + 1;
        prevs[i] = j - 1;

        if (lengths[i] > lengths[maxI]) maxI = i;
      }
    }
  }

  const int outputSize = lengths[maxI];
  char** output = malloc(outputSize * sizeof(char*));
  for (int i = outputSize - 1; i >= 0; --i) {
    output[i] = words[maxI];
    maxI = prevs[maxI];
  }

  *returnSize = outputSize;

  free(wordLens);
  free(lengths);
  free(prevs);

  return output;
}

static bool validHammingDistance(char* a, int aSize, char* b) {
  for (int i = 0; i < aSize; ++i) {
    if (a[i] != b[i]) {
      while (++i < aSize) {
        if (a[i] != b[i]) return false;
      }
      return true;
    }
  }
  return false;
}

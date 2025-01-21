#include <stdlib.h>
#include <string.h>

int* vowelStrings(
    char** words, int wordsSize,
    int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
  (void)queriesColSize;

  int* prefixCounts = malloc((wordsSize + 1) * sizeof(int));
  prefixCounts[0] = 0;

  int count = 0;
  for (int i = 0; i < wordsSize; ++i) {
    switch (words[i][0]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        switch (words[i][strlen(words[i]) - 1]) {
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'u':
            ++count;
        }
    }
    prefixCounts[i + 1] = count;
  }

  int* output = malloc(queriesSize * sizeof(int));
  for (int i = 0; i < queriesSize; ++i) {
    output[i] = prefixCounts[queries[i][1] + 1] - prefixCounts[queries[i][0]];
  }

  *returnSize = queriesSize;
  return output;
}

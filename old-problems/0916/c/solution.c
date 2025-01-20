#include <stdlib.h>

char** wordSubsets(
    char** words1, int words1Size,
    char** words2, int words2Size, int* returnSize) {
  int maxFreqs[26] = {0};
  for (int i = 0; i < words2Size; ++i) {
    int freqs[26] = {0};
    for (char* c = words2[i]; *c != 0; ++c) ++freqs[*c - 'a'];

    for (int j = 0; j < 26; ++j) {
      if (freqs[j] > maxFreqs[j]) maxFreqs[j] = freqs[j];
    }
  }

  char** output = malloc(words1Size * sizeof(char*));
  int outputSize = 0;

  for (int i = 0; i < words1Size; ++i) {
    int freqs[26] = {0};
    for (char* c = words1[i]; *c != 0; ++c) ++freqs[*c - 'a'];

    int j = 0;
    while (j < 26) {
      if (freqs[j] < maxFreqs[j]) break;
      ++j;
    }

    if (j == 26) {
      output[outputSize++] = words1[i];
    }
  }

  *returnSize = outputSize;
  return output;
}

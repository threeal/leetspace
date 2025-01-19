#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
  return strlen(*(char**)a) - strlen(*(char**)b);
}

char** stringMatching(char** words, int wordsSize, int* returnSize) {
  qsort(words, wordsSize, sizeof(char*), compare);

  char** output = malloc(wordsSize * sizeof(char*));
  int outputSize = 0;

  for (int i = 0; i < wordsSize; ++i) {
    for (int j = i + 1; j < wordsSize; ++j) {
      if (strstr(words[j], words[i]) != NULL) {
        output[outputSize++] = words[i];
        break;
      }
    }
  }

  *returnSize = outputSize;
  return output;
}

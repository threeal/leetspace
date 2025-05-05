#include <stdlib.h>

int* findWordsContaining(char** words, int wordsSize, char x, int* returnSize) {
  int* output = malloc(wordsSize * sizeof(int));
  int outputSize = 0;

  for (int i = 0; i < wordsSize; ++i) {
    for (char* c = words[i]; *c != 0; ++c) {
      if (*c == x) {
        output[outputSize++] = i;
        break;
      }
    }
  }

  *returnSize = outputSize;
  return output;
}

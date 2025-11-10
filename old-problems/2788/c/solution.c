#include <stdlib.h>

char** splitWordsBySeparator(
    char** words, int wordsSize, char separator, int* returnSize) {
  int maxOutputSize = wordsSize;
  char** output = malloc(maxOutputSize * sizeof(char*));
  int outputSize = 0;

  for (int i = 0; i < wordsSize; ++i) {
    int l = 0, r = 0;
    while (words[i][r] != 0) {
      if (words[i][r] == separator) {
        if (r - l > 0) {
          if (outputSize == maxOutputSize) {
            maxOutputSize *= 2;
            output = realloc(output, maxOutputSize * sizeof(char*));
          }
          output[outputSize++] = words[i] + l;
          words[i][r] = 0;
        }
        l = r + 1;
      }
      ++r;
    }

    if (r - l > 0) {
      if (outputSize == maxOutputSize) {
        maxOutputSize *= 2;
        output = realloc(output, maxOutputSize * sizeof(char*));
      }
      output[outputSize++] = words[i] + l;
      words[i][r] = 0;
    }
  }

  *returnSize = outputSize;
  return output;
}

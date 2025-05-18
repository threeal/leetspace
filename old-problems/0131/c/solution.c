#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void partitionRecursively(
    char**** output, int* outputMaxSize, int* outputSize, int** outputColSize,
    char* s, int sLen, int n);

static bool isPalindrome(const char* s, int left, int right);

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
  int outputMaxSize = 32;
  char*** output = malloc(outputMaxSize * sizeof(char**));
  *returnColumnSizes = malloc(outputMaxSize * sizeof(int));
  *returnSize = 0;

  const int sLen = strlen(s);
  partitionRecursively(
      &output, &outputMaxSize, returnSize, returnColumnSizes, s, sLen, sLen);

  return output;
}

static void partitionRecursively(
    char**** output, int* outputMaxSize, int* outputSize, int** outputColSize,
    char* s, int sLen, int n) {
  for (int i = n - 1; i >= 0; --i) {
    if (isPalindrome(s, i, n - 1)) {
      if (i == 0) {
        const int j = *outputSize;
        if (j >= *outputMaxSize) {
          *outputMaxSize *= 32;
          *output = realloc(*output, *outputMaxSize * sizeof(char**));
          *outputColSize = realloc(
              *outputColSize, *outputMaxSize * sizeof(int));
        }

        (*output)[j] = malloc(sLen * sizeof(char*));
        (*output)[j][0] = malloc((n - i + 1) * sizeof(char));
        memcpy((*output)[j][0], s + i, (n - i) * sizeof(char));
        (*output)[j][0][n - i] = 0;
        (*outputColSize)[j] = 1;
        ++(*outputSize);
      } else {
        int j = *outputSize;
        partitionRecursively(
            output, outputMaxSize, outputSize, outputColSize, s, sLen, i);

        while (j < *outputSize) {
          const int k = (*outputColSize)[j];
          (*output)[j][k] = malloc((n - i + 1) * sizeof(char));
          memcpy((*output)[j][k], s + i, (n - i) * sizeof(char));
          (*output)[j][k][n - i] = 0;
          ++(*outputColSize)[j];
          ++j;
        }
      }
    }
  }
}

static bool isPalindrome(const char* s, int left, int right) {
  while (left < right) {
    if (s[left] != s[right]) return false;
    ++left;
    --right;
  }
  return true;
}

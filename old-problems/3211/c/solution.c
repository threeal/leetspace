#include <stdlib.h>
#include <string.h>

char** output = NULL;
int outputSize;

char str[19];

static void generate(int n, int i);

char** validStrings(int n, int* returnSize) {
  if (output == NULL) {
    output = malloc(6765 * sizeof(char*));
    for (int i = 0; i < 6765; ++i) output[i] = NULL;
  }
  outputSize = 0;
  memset(str, '0', n * sizeof(char));
  generate(n, 1);

  str[0] = '1';
  generate(n, 1);

  *returnSize = outputSize;
  return output;
}

static void generate(int n, int i) {
  if (i == n) {
    if (output[outputSize] == NULL) {
      output[outputSize] = malloc(19 * sizeof(char));
    }
    memcpy(output[outputSize], str, n * sizeof(char));
    output[outputSize][n] = 0;
    ++outputSize;
  } else {
    if (str[i - 1] == '1') {
      str[i] = '0';
      generate(n, i + 1);
    }

    str[i] = '1';
    generate(n, i + 1);
  }
}

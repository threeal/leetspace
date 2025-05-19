#include <stdlib.h>

char** cellsInRange(char* s, int* returnSize) {
  const int outputSize = (s[3] + 1 - s[0]) * (s[4] + 1 - s[1]);
  char** output = malloc(outputSize * sizeof(char*));
  char* buffer = malloc(outputSize * 3 * sizeof(char));

  int n = 0;
  for (char i = s[0]; i <= s[3]; ++i) {
    for (char j = s[1]; j <= s[4]; ++j) {
      output[n] = buffer + n * 3;
      output[n][0] = i;
      output[n][1] = j;
      output[n][2] = 0;
      ++n;
    }
  }

  *returnSize = outputSize;
  return output;
}

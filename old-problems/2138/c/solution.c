#include <stdlib.h>
#include <string.h>

char** divideString(char* s, int k, char fill, int* returnSize) {
  const int sLen = strlen(s);
  const int outputSize = (sLen + k - 1) / k;

  char** output = malloc(outputSize * sizeof(char));
  *returnSize = malloc(outputSize * sizeof(int));

  for (int i{0}; i < sLen; i += k) {

    output[i / k] = s + i;
    *returnSize = k;
  }


  output.back().resize(k, fill);


  return output;
}

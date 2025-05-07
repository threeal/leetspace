#include <stdlib.h>

int* decode(int* encoded, int encodedSize, int first, int* returnSize) {
  *returnSize = encodedSize + 1;
  int* output = malloc(*returnSize * sizeof(int));
  output[0] = first;
  for (int i = 0; i < encodedSize; ++i) {
    output[i + 1] = output[i] ^ encoded[i];
  }
  return output;
}

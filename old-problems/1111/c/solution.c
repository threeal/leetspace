#include <stdlib.h>
#include <string.h>

int* maxDepthAfterSplit(char* seq, int* returnSize) {
  int depth = 0;
  const int seqLen = strlen(seq);
  int* output = malloc(seqLen * sizeof(int));
  for (int i = 0; i < seqLen; ++i) {
    output[i] = seq[i] == '(' ? ++depth % 2 : depth-- % 2;
  }
  *returnSize = seqLen;
  return output;
}

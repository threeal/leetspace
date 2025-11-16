#include <stdlib.h>

int* pathInZigZagTree(int label, int* returnSize) {
  int level = 0;
  while (1 << level <= label) ++level;

  int* output = malloc(level * sizeof(int));
  *returnSize = level;

  while (label > 0) {
    output[level - 1] = label;
    label = ((1 << level) - 1 - label + (1 << (level - 1))) / 2;
    --level;
  }

  return output;
}

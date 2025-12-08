#include <stdlib.h>
#include <string.h>

int* minOperations(char* boxes, int* returnSize) {
  const int boxesLen = strlen(boxes);
  int* operations = malloc(boxesLen * sizeof(int));
  memset(operations, 0, boxesLen * sizeof(int));

  int n = 0, operation = 0;
  for (int i = 0; i < boxesLen; ++i) {
    operation += n;
    operations[i] += operation;
    if (boxes[i] == '1') ++n;
  }

  n = 0;
  operation = 0;

  for (int i = boxesLen - 1; i >= 0; --i) {
    operation += n;
    operations[i] += operation;
    if (boxes[i] == '1') ++n;
  }

  *returnSize = boxesLen;
  return operations;
}

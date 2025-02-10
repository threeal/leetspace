#include <stdlib.h>

int sumSubarrayMins(int* arr, int arrSize) {
  int* posStack = malloc(arrSize * sizeof(int));
  int* valStack = malloc(arrSize * sizeof(int));
  int stackIdx = -1;

  for (int i = 0; i < arrSize; ++i) {
    while (stackIdx >= 0 && valStack[stackIdx] >= arr[i]) --stackIdx;
    if (stackIdx < 0) {
      posStack[++stackIdx] = i;
      valStack[stackIdx] = arr[i];
      arr[i] = ((long long)arr[i] * (i + 1)) % 1000000007;
    } else {
      const int j = posStack[stackIdx];
      posStack[++stackIdx] = i;
      valStack[stackIdx] = arr[i];
      arr[i] = (arr[j] + (long long)arr[i] * (i - j)) % 1000000007;
    }
  }

  int sum = 0;
  for (int i = 0; i < arrSize; ++i) {
    sum = (sum + arr[i]) % 1000000007;
  }
  return sum;
}

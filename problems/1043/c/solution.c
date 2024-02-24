#include <stdlib.h>

int recursive(int* arr, int arrSize, int k, int* cache, int i, int maxVal, int len);

int maxSumAfterPartitioning(int* arr, int arrSize, int k) {
  int* cache = malloc(sizeof(int) * arrSize);
  for (int i = 0; i < arrSize; ++i) {
    cache[i] = -1;
  }
  return recursive(arr, arrSize, k, cache, 1, arr[0], 1);
}

int recursive(int* arr, int arrSize, int k, int* cache, int i, int maxVal, int len) {
  if (i >= arrSize) {
    return maxVal * len;
  }

  if (len >= k) {
    return maxVal * len + recursive(arr, arrSize, k, cache, i + 1, arr[i], 1);
  }

  if (len == 1 && cache[i] > 0) {
    return cache[i];
  }

  const int pick = recursive(arr, arrSize, k, cache, i + 1, maxVal > arr[i] ? maxVal : arr[i], len + 1);
  const int notPick = maxVal * len + recursive(arr, arrSize, k, cache, i + 1, arr[i], 1);
  const int res = pick > notPick ? pick : notPick;

  if (len == 1) {
    cache[i] = res;
  }

  return res;
}

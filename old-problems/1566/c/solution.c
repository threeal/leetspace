#include <stdbool.h>

bool compareSubarrays(int* a, int* b, int m) {
  for (int i = m - 1; i >= 0; --i) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

bool checkSubarrays(int* arr, int m, int k) {
  for (int i = k - 2; i >= 0; --i) {
    if (!compareSubarrays(arr + i * m, arr + i * m + m, m)) return false;
  }
  return true;
}

bool containsPattern(int* arr, int arrSize, int m, int k) {
  for (int i = arrSize - m * k; i >= 0; --i) {
    if (checkSubarrays(arr + i, m, k)) return true;
  }
  return false;
}

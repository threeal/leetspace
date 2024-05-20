#include <stdlib.h>

int* kthSmallestPrimeFraction(int* arr, int arrSize, int k, int* returnSize) {
  *returnSize = 2;
  int* returnData = malloc(2 * sizeof(int));

  double left = 0.0;
  double right = 1.0;
  while (left <= right) {
    const double mid = left + (right - left) / 2.0;

    int total = 0;
    int den = 1;
    double maxFrac = 0.0;
    int selectedNum = 0;
    int selectedDen = 0;
    for (int num = 0; num < arrSize; ++num) {
      while (den < arrSize && arr[num] >= arr[den] * mid) ++den;
      total += arrSize - den;

      if (den < arrSize && maxFrac < (double)arr[num] / (double)arr[den]) {
        maxFrac = (double)arr[num] / (double)arr[den];
        selectedNum = num;
        selectedDen = den;
      }
    }

    if (total == k) {
      returnData[0] = arr[selectedNum];
      returnData[1] = arr[selectedDen];
      return returnData;
    };

    if (total > k) {
      right = mid;
    } else {
      left = mid;
    }
  }

  return returnData;
}

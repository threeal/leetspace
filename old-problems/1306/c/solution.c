#include <stdbool.h>

bool canReach(int* arr, int arrSize, int start) {
  const int val = arr[start];
  switch (val) {
    case -1:
      return false;

    case 0:
      return true;

    default:
      arr[start] = -1;
      if (val <= start && canReach(arr, arrSize, start - val)) {
        arr[start] = 0;
        return true;
      }

      if (start + val < arrSize && canReach(arr, arrSize, start + val)) {
        arr[start] = 0;
        return true;
      }

      arr[start] = -1;
      return false;
  }
}

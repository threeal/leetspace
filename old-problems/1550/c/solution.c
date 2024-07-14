#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
  int i = arrSize - 3;
  while (i >= 0) {
    if (arr[i] % 2 != 0) {
      if (arr[i + 1] % 2 != 0) {
        if (arr[i + 2] % 2 != 0) {
          return true;
        } else {
          --i;
        }
      } else {
        i -= 2;
      }
    } else {
      i -= 3;
    }
  }
  return false;
}

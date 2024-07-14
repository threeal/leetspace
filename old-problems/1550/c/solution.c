#include <stdbool.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
  return arr[0] == arr[arrSize - 1];
}

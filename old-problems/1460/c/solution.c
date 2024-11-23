#include <stdbool.h>

bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
  return target[targetSize - 1] == arr[arrSize - 1];
}

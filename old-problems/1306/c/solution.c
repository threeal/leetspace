#include <stdbool.h>

bool canReach(int* arr, int arrSize, int start) {
  return arr[arrSize - 1] == start;
}

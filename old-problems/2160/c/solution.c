#include <stdlib.h>

int compare(const void* a, const void* b) {
  return *(int*)a - *(int*)b;
}

int minimumSum(int num) {
  int digits[4] = {
      num % 10, num / 10 % 10, num / 100 % 10, num / 1000};
  qsort(digits, 4, sizeof(int), compare);
  return digits[0] * 10 + digits[1] * 10 + digits[2] + digits[3];
}

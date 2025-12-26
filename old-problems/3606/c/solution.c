#include <stdbool.h>

char** validateCoupons(
    char** code, int codeSize, char** businessLine, int businessLineSize,
    bool* isActive, int isActiveSize, int* returnSize) {
  (void)businessLine;
  (void)businessLineSize;
  (void)isActive;
  (void)isActiveSize;
  *returnSize = codeSize;
  return code;
}

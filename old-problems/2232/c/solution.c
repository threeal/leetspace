#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

char* minimizeResult(char* expression) {
  int minOutLeft = 0, minLeft = 0, minRight = 0, minOutRight = 0;
  int minRes = INT_MAX;

  int outLeft = 0;
  char* c1 = expression;
  while (*c1 != '+') {
    int left = 0;
    char* c2 = c1;
    while (*c2 != '+') {
      left = left * 10 + *c2 - '0';
      ++c2;
    }

    int right = 0;
    char* c3 = c2 + 1;
    while (*c3 != 0) {
      right = right * 10 + *c3 - '0';

      int outRight = 0;
      char* c4 = c3 + 1;
      while (*c4 != 0) {
        outRight = outRight * 10 + *c4 - '0';
        ++c4;
      }

      int res = left + right;
      if (outLeft > 0) res *= outLeft;
      if (outRight > 0) res *= outRight;
      if (res < minRes) {
        minOutLeft = outLeft;
        minLeft = left;
        minRight = right;
        minOutRight = outRight;
        minRes = res;
      }

      ++c3;
    }

    outLeft = outLeft * 10 + *c1 - '0';
    ++c1;
  }

  char* out = malloc(13 * sizeof(char));
  if (minOutLeft > 0) {
    if (minOutRight > 0) {
      sprintf(out, "%d(%d+%d)%d", minOutLeft, minLeft, minRight, minOutRight);
    } else {
      sprintf(out, "%d(%d+%d)", minOutLeft, minLeft, minRight);
    }
  } else {
    if (minOutRight > 0) {
      sprintf(out, "(%d+%d)%d", minLeft, minRight, minOutRight);
    } else {
      sprintf(out, "(%d+%d)", minLeft, minRight);
    }
  }
  return out;
}

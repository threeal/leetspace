#include <math.h>
#include <stdbool.h>

bool judgeSquareSum(int c) {
  unsigned int a = 0;
  unsigned int b = sqrt(c);

  unsigned int a2 = 0;
  unsigned int b2 = b * b;

  while (a <= b) {
    if (c - a2 <= b2) {
      if (c - a2 == b2) return true;
      --b;
      b2 = b * b;
    } else {
      ++a;
      a2 = a * a;
    }
  }

  return false;
}

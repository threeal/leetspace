#include <stdlib.h>

char* convertToBase7(int num) {
  if (num == 0) return "0";

  const int neg = num < 0;
  if (neg) num = -num;

  char* out = malloc(11 * sizeof(char));
  *(out += 10) = 0;

  while (num > 0) {
    *(--out) = '0' + num % 7;
    num /= 7;
  }

  if (neg) *(--out) = '-';
  return out;
}

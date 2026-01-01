#include <stdint.h>

char* greatestLetter(char* s) {
  uint32_t upper = 0, lower = 0;
  for (char* c = s; *c != 0; ++c) {
    if (*c >= 'a') {
      lower |= 1 << (*c - 'a');
    } else {
      upper |= 1 << (*c - 'A');
    }
  }

  upper &= lower;
  if (upper == 0) return "";

  s[0] = 'A' + 31 - __builtin_clz(upper);
  s[1] = 0;

  return s;
}

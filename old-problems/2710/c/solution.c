#include <string.h>

char* removeTrailingZeros(char* num) {
  int n = strlen(num) - 1;
  while (n >= 0 && num[n] == '0') --n;
  num[n + 1] = 0;
  return num;
}

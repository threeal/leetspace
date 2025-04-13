#include <stdlib.h>

char* toHex(int num) {
  if (num == 0) return "0";

  int n = 28;
  while (num >> n == 0) n -= 4;

  int hexLen = 2 + n / 4;
  char* hex = malloc(hexLen * sizeof(char));
  for (int i = 0; i <= n; i += 4) {
    const int val = (num >> i) & 15;
    hex[(n - i) / 4] = val >= 10 ? 'a' + val - 10 : '0' + val;
  }

  hex[hexLen - 1] = 0;
  return hex;
}

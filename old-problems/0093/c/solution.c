#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static bool isValidDigits(char* s, int sLen, int i, int n);

char** restoreIpAddresses(char* s, int* returnSize) {
  const int sLen = strlen(s);

  char* out = malloc((sLen + 4) * sizeof(char));
  out[sLen + 3] = 0;

  char** output = malloc(81 * sizeof(char*));
  int outputSize = 0;

  for (int a = 1; isValidDigits(s, sLen, 0, a); ++a) {
    for (int i = 0; i < a; ++i) out[i] = s[i];
    out[a] = '.';

    for (int b = 1; isValidDigits(s, sLen, a, b); ++b) {
      const int ab = a + b;

      for (int i = 0; i < b; ++i) out[a + 1 + i] = s[a + i];
      out[ab + 1] = '.';

      for (int c = 1; ab + c < sLen; ++c) {
        const int abc = ab + c;
        const int d = sLen - abc;

        if (isValidDigits(s, sLen, ab, c) && isValidDigits(s, sLen, abc, d)) {
          for (int i = 0; i < c; ++i) out[ab + 2 + i] = s[ab + i];
          out[abc + 2] = '.';

          for (int i = 0; i < d; ++i) out[abc + 3 + i] = s[abc + i];

          output[outputSize] = malloc((sLen + 4) * sizeof(char));
          memcpy(output[outputSize], out, (sLen + 4) * sizeof(char));
          ++outputSize;
        }
      }
    }
  }

  free(out);

  *returnSize = outputSize;
  return output;
}

static bool isValidDigits(char* s, int sLen, int i, int n) {
  if (i + n > sLen) return false;
  switch (n) {
    case 1:
      return true;

    case 2:
      return s[i] != '0';

    case 3: {
      const char c0 = s[i], c1 = s[i + 1], c2 = s[i + 2];
      return c0 == '1' || (c0 == '2' && (c1 < '5' || (c1 == '5' && c2 <= '5')));
    }
  }
  return false;
}

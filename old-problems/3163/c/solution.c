#include <stdlib.h>
#include <string.h>

char* compressedString(char* word) {
  char* out = malloc((1 + (2 * strlen(word))) * sizeof(char));
  int outLen = 0;

  int i = 0;
  while (word[i] != 0) {
    const char c = word[i];

    int n = 1;
    while (word[i + n] == c) ++n;
    i += n;

    while (n > 0) {
      if (n > 9) {
        out[outLen++] = '9';
        n -= 9;
      } else {
        out[outLen++] = '0' + n;
        n = 0;
      }
      out[outLen++] = c;
    }
  }

  out[outLen] = 0;
  return out;
}

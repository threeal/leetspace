#include <stdlib.h>
#include <string.h>

char* addSpaces(char* s, int* spaces, int spacesSize) {
  char* ps = s;
  const int psSize = strlen(ps);

  int l = psSize - 1;
  int i = spacesSize - 1;

  const int sSize = psSize + spacesSize;
  s = malloc((sSize + 1) * sizeof(char));
  memcpy(s, ps, psSize * sizeof(char));
  memset(s + psSize, ' ', (sSize - psSize) * sizeof(char));
  s[sSize] = 0;
  int r = sSize - 1;

  while (l >= 0) {
    if (l == spaces[i] - 1) {
      if (--i < 0) break;
    } else {
      s[r] = s[l];
      s[l] = ' ';
      --l;
    }
    --r;
  }

  return s;
}

#include <stdlib.h>
#include <string.h>

char* shiftingLetters(
    char* s, int** shifts, int shiftsSize, int* shiftsColSize) {
  (void)shiftsColSize;

  const int sLen = strlen(s);

  int* prefixes = malloc((sLen + 1) * sizeof(int));
  memset(prefixes, 0, (sLen + 1) * sizeof(int));

  for (int i = 0; i < shiftsSize; ++i) {
    if (shifts[i][2] == 0) {
      --prefixes[shifts[i][0]];
      ++prefixes[shifts[i][1] + 1];
    } else {
      ++prefixes[shifts[i][0]];
      --prefixes[shifts[i][1] + 1];
    }
  }

  int shift = 0;
  for (int i = 0; i < sLen; ++i) {
    shift = (shift + prefixes[i]) % 26;
    s[i] = 'a' + ((s[i] - 'a' + shift) % 26 + 26) % 26;
  }

  return s;
}

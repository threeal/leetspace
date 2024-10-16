#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int minExtraChar(char* s, char** dictionary, int dictionarySize) {
  int sSize = strlen(s);
  int* extraChars = malloc(sSize * sizeof(int));
  for (int i = 0; i < sSize; ++i) extraChars[i] = sSize;

  for (int r = 0; r < sSize; ++r) {
    extraChars[r] = r > 0 ? extraChars[r - 1] + 1 : 1;
    for (int i = 0; i < dictionarySize; ++i) {
      int wordSize = strlen(dictionary[i]);
      if (r + 1 < wordSize) continue;

      char* sShifted = s + r + 1 - wordSize;
      for (int j = 0; j < wordSize; ++j) {
        if (sShifted[j] != dictionary[i][j]) goto next;
      }

      if (r >= wordSize) {
        if (extraChars[r - wordSize] < extraChars[r]) {
          extraChars[r] = extraChars[r - wordSize];
        }
      } else {
        extraChars[r] = 0;
      }

    next:;
    }
  }

  return extraChars[sSize - 1];
}

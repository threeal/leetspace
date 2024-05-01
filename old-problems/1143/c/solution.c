#include <stdlib.h>
#include <string.h>

int longestCommonSubsequence(char* text1, char* text2) {
  const int text2Size = strlen(text2);

  const int lengthsSize = (text2Size + 1) * sizeof(int);
  int* lengths = malloc(lengthsSize);
  int* prevLengths = malloc(lengthsSize);

  memset(lengths, 0, lengthsSize);

  while (*text1 != 0) {
    memcpy(prevLengths, lengths, lengthsSize);
    memset(lengths, 0, lengthsSize);

    for (int j = 0; j < text2Size; ++j) {
      lengths[j + 1] = *text1 == text2[j]
          ? 1 + prevLengths[j]
          : (lengths[j] > prevLengths[j + 1] ? lengths[j] : prevLengths[j + 1]);
    }

    ++text1;
  }

  const int length = lengths[text2Size];

  free(lengths);
  free(prevLengths);

  return length;
}

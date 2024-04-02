#include <stdlib.h>
#include <string.h>

int fn(int** cache, char* text1, char* text2, int text1Size, int text2Size, int i1, int i2);

int longestCommonSubsequence(char* text1, char* text2) {
  const int text1Size = strlen(text1);
  const int text2Size = strlen(text2);

  int** cache = malloc(sizeof(int*) * text1Size);
  for (int i1 = 0; i1 < text1Size; ++i1) {
    cache[i1] = malloc(sizeof(int) * text2Size);
    for (int i2 = 0; i2 < text2Size; ++i2) {
      cache[i1][i2] = -1;
    }
  }

  const int res = fn(cache, text1, text2, text1Size, text2Size, 0, 0);

  for (int i1 = 0; i1 < text1Size; ++i1) {
    free(cache[i1]);
  }
  free(cache);

  return res;
}

int fn(int** cache, char* text1, char* text2, int text1Size, int text2Size, int i1, int i2) {
  if (i1 >= text1Size || i2 >= text2Size) return 0;

  if (cache[i1][i2] < 0) {
    if (text1[i1] == text2[i2]) {
      const int a = 1 + fn(cache, text1, text2, text1Size, text2Size, i1 + 1, i2 + 1);
      const int b = fn(cache, text1, text2, text1Size, text2Size, i1 + 1, i2);
      const int c = fn(cache, text1, text2, text1Size, text2Size, i1, i2 + 1);
      cache[i1][i2] = a > b && a > c ? a : (b > c ? b : c);
    } else {
      const int a = fn(cache, text1, text2, text1Size, text2Size, i1 + 1, i2);
      const int b = fn(cache, text1, text2, text1Size, text2Size, i1, i2 + 1);
      cache[i1][i2] = a > b ? a : b;
    }
  }

  return cache[i1][i2];
}

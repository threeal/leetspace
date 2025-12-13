#include <stdbool.h>

char gTwoDigits[32][10];
bool gTwoDigitsInitialized = false;

void initializeTwoDigits(void) {
  if (!gTwoDigitsInitialized) {
    gTwoDigitsInitialized = true;
    for (int i = 0; i < 32; ++i) {
      unsigned int n = 1u << i;
      while (n != 0) {
        ++gTwoDigits[i][n % 10];
        n /= 10;
      }
    }
  }
}

bool reorderedPowerOf2(int n) {
  initializeTwoDigits();

  char digits[10] = {0};
  while (n != 0) {
    ++digits[n % 10];
    n /= 10;
  }

  for (int i = 0; i < 32; ++i) {
    int j = 0;
    while (j < 10 && digits[j] == gTwoDigits[i][j]) ++j;
    if (j == 10) return true;
  }

  return false;
}

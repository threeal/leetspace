#include <stdio.h>
#include <stdlib.h>

char* getHint(char* secret, char* guess) {
  int missingSecret[10] = {0};
  int missingGuess[10] = {0};

  int bulls = 0;
  for (int i = 0; secret[i] != 0; ++i) {
    if (secret[i] == guess[i]) {
      ++bulls;
    } else {
      ++missingSecret[secret[i] - '0'];
      ++missingGuess[guess[i] - '0'];
    }
  }

  int cows = 0;
  for (int i = 9; i >= 0; --i) {
    cows += missingSecret[i] < missingGuess[i]
        ? missingSecret[i]
        : missingGuess[i];
  }

  char* str = malloc(10 * sizeof(char));
  sprintf(str, "%dA%dB", bulls, cows);
  return str;
}

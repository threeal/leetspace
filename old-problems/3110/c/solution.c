#include <stdlib.h>

int scoreOfString(char* s) {
  int score = 0;
  while (s[1] != 0) {
    score += abs(s[0] - s[1]);
    ++s;
  }
  return score;
}

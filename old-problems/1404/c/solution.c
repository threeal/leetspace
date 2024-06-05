#include <string.h>

int numSteps(char* s) {
  int steps = 0;
  int i = strlen(s) - 1;

  while (i > 0 && s[i] == '0') {
    --i;
    ++steps;
  }

  while (i > 0) {
    steps += 2;
    --i;
    while (i >= 0 && s[i] == '1') {
      --i;
      ++steps;
    }
  }

  return steps;
}

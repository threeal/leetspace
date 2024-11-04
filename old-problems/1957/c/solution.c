#include <stdbool.h>

char* makeFancyString(char* s) {
  int out = 0;
  char prev = 0;
  bool twice = false;

  for (char* c = s; *c != 0; ++c) {
    if (*c != prev) {
      prev = *c;
      twice = false;
    } else {
      if (twice) continue;
      twice = true;
    }

    s[out++] = *c;
  }

  s[out++] = 0;
  return s;
}

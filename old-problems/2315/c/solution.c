#include <stdbool.h>

int countAsterisks(char* s) {
  bool ignore = false;
  int count = 0;
  for (int i = 0; s[i] != 0; ++i) {
    if (s[i] == '|') {
      ignore = !ignore;
    } else if (s[i] == '*' && !ignore) {
      ++count;
    }
  }
  return count;
}

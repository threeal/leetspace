#include <stdbool.h>

bool canChange(char* start, char* target) {
  int l = 0, r = 0;
  for (int i = 0; start[i] != 0; ++i) {
    if (start[i] == 'R') {
      if (l > 0) return false;
      ++r;
    }
    if (target[i] == 'L') {
      if (r > 0) return false;
      ++l;
    }
    if (start[i] == 'L') {
      if (l == 0) return false;
      --l;
    }
    if (target[i] == 'R') {
      if (r == 0) return false;
      --r;
    }
  }

  return l == 0 && r == 0;
}

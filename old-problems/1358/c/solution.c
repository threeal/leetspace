#include <stdbool.h>

int numberOfSubstrings(char* s) {
  int r = 0, a = 0, b = 0, c = 0, valid = 0;
  while (s[r] != 0 && valid < 3) {
    switch (s[r]) {
      case 'a':
        if (++a == 1) ++valid;
        break;
      case 'b':
        if (++b == 1) ++valid;
        break;
      case 'c':
        if (++c == 1) ++valid;
        break;
    }
    ++r;
  }

  if (valid < 3) return 0;

  int l = 0, count = 0;
  while (true) {
    bool stop = false;
    while (!stop) {
      switch (s[l]) {
        case 'a':
          if (a > 1) {
            ++l;
            --a;
          } else {
            stop = true;
          }
          break;
        case 'b':
          if (b > 1) {
            ++l;
            --b;
          } else {
            stop = true;
          }
          break;
        case 'c':
          if (c > 1) {
            ++l;
            --c;
          } else {
            stop = true;
          }
          break;
      }
    }
    count += l + 1;

    if (s[r] == 0) break;

    switch (s[r]) {
      case 'a':
        ++a;
        break;
      case 'b':
        ++b;
        break;
      case 'c':
        ++c;
        break;
    }

    ++r;
  }

  return count;
}

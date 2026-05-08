#include <stdbool.h>
#include <string.h>

char* trimTrailingVowels(char* s) {
  bool done = false;
  int n = strlen(s);
  while (!done) {
    switch (s[n - 1]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        if (--n == 0) {
          done = true;
        }
        break;

      default:
        done = true;
    }
  }
  s[n] = 0;
  return s;
}

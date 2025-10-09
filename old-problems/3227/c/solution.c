#include <stdbool.h>

bool doesAliceWin(char* s) {
  for (int i = 0; s[i] != 0; ++i) {
    switch (s[i]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        return true;
    }
  }
  return false;
}

#include <stdbool.h>

bool checkValidString(char* s) {
  int minLevel = 0;
  int maxLevel = 0;

  while (*s != 0) {
    switch (*s) {
      case '(':
        ++minLevel;
        ++maxLevel;
        break;

      case ')':
        --minLevel;
        --maxLevel;
        break;

      case '*':
        --minLevel;
        ++maxLevel;
        break;
    }

    if (maxLevel < 0) return false;
    if (minLevel < 0) minLevel = 0;
    ++s;
  }

  return minLevel == 0;
}

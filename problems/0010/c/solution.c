#include <stdbool.h>

bool isMatch(char* s, char* p) {
  if (p[0] == 0) {
    return s[0] == 0;
  } else if (s[0] == 0) {
    if (p[0] != 0 && p[1] == '*') {
      return isMatch(s, p + 2);
    } else {
      return false;
    }
  } else if (p[0] != 0 && p[1] == '*') {
    if (s[0] == p[0] || p[0] == '.') {
      if (isMatch(s + 1, p)) {
        return true;
      } else {
        return isMatch(s, p + 2);
      }
    } else {
      return isMatch(s, p + 2);
    }
  } else if (s[0] == p[0] || p[0] == '.') {
    return isMatch(s + 1, p + 1);
  } else {
    return false;
  }
}

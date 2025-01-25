#include <stdbool.h>

bool isValid(char* s) {
  int i = 0;
  for (char* c = s; *c != 0; ++c) {
    switch (*c) {
      case '(':
      case '[':
      case '{':
        s[i] = *c;
        ++i;
        break;

      case ')':
        if (i == 0 || s[i - 1] != '(') return false;
        --i;
        break;

      case ']':
        if (i == 0 || s[i - 1] != '[') return false;
        --i;
        break;

      case '}':
        if (i == 0 || s[i - 1] != '{') return false;
        --i;
        break;
    }
  }
  return i == 0;
}

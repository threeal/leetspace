#include <stdlib.h>

char* processStr(char* s) {
  int resLen = 0;
  int maxResLen = 128;
  char* res = malloc(maxResLen * sizeof(char));

  for (char* c = s; *c != 0; ++c) {
    switch (*c) {
      case '*':
        if (resLen > 0) --resLen;
        break;

      case '#':
        if (resLen * 2 >= maxResLen) {
          maxResLen *= 4;
          res = realloc(res, maxResLen * sizeof(char));
        }
        for (int i = 0; i < resLen; ++i) {
          res[resLen + i] = res[i];
        }
        resLen *= 2;
        break;

      case '%':
        for (int l = 0, r = resLen - 1; l < r; ++l, --r) {
          const int temp = res[l];
          res[l] = res[r];
          res[r] = temp;
        }
        break;

      default:
        res[resLen++] = *c;
        if (resLen >= maxResLen) {
          maxResLen *= 4;
          res = realloc(res, maxResLen * sizeof(char));
        }
    }
  }

  res[resLen] = 0;
  return res;
}

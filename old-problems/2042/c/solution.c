#include <stdbool.h>
#include <string.h>

bool areNumbersAscending(char* s) {
  int prev = -1;
  const int sLen = strlen(s);
  for (int i = 0; i < sLen; ++i) {
    int num = 0;
    while (i < sLen && s[i] != ' ') {
      if (num != -1 && s[i] <= '9') {
        num = num * 10 + s[i] - '0';
      } else {
        num = -1;
      }
      ++i;
    }

    if (num == -1) continue;
    if (num > prev) {
      prev = num;
    } else {
      return false;
    }
  }
  return true;
}

#include <stdlib.h>

char* countAndSay(int n) {
  char* str = malloc(4463 * sizeof(int));
  int strLen = 0;
  str[strLen++] = '1';

  char* prev = malloc(3411 * sizeof(int));
  int prevLen = 0;

  while (--n > 0) {
    char* temp = prev;
    prev = str;
    str = temp;

    prevLen = strLen;
    strLen = 0;

    int count = 1;
    for (int i = 1; i <= prevLen; ++i) {
      if (prev[i] != prev[i - 1]) {
        int exp = 1;
        while (exp * 10 <= count) exp *= 10;
        while (exp > 0) {
          str[strLen++] = '0' + count / exp;
          exp /= 10;
        }
        str[strLen++] = prev[i - 1];
        count = 1;
      } else {
        ++count;
      }
    }
  }

  str[strLen] = 0;
  return str;
}

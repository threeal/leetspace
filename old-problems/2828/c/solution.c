#include <stdbool.h>

bool canMakeSubsequence(char* str1, char* str2) {
  for (char *c1 = str1, *c2 = str2; *c1 != 0; ++c1) {
    if (*c1 == *c2 || (*c1 + 1 - 'a') % 26 == *c2 - 'a') {
      if (*(++c2) == 0) return true;
    }
  }
  return false;
}

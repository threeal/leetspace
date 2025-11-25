#include <string.h>

int maximumValue(char** strs, int strsSize) {
  int maxVal = 0;
  for (int i = 0; i < strsSize; ++i) {
    int val = 0;
    for (char* c = strs[i]; *c != 0; ++c) {
      if (*c >= '0' && *c <= '9') {
        val = val * 10 + *c - '0';
      } else {
        val = strlen(strs[i]);
        break;
      }
    }
    if (val > maxVal) maxVal = val;
  }
  return maxVal;
}

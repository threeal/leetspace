#include <string.h>

int strStr(char* haystack, char* needle) {
  const int haystackLen = strlen(haystack);
  const int needleLen = strlen(needle);
  if (haystackLen >= needleLen) {
    for (int i = 0; i <= haystackLen - needleLen; ++i) {
      if (strncmp(haystack + i, needle, needleLen) == 0) return i;
    }
  }
  return -1;
}

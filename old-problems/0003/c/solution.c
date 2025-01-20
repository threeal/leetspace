#include <string.h>

int lengthOfLongestSubstring(char* s) {
  int longest = 0, sLen = strlen(s);
  unsigned char exists[256] = {0};
  for (int l = 0, r = 0; r < sLen; ++r) {
    while (exists[s[r]]) {
      exists[s[l]] = 0;
      ++l;
    }
    exists[s[r]] = 1;
    if (r - l + 1 > longest) longest = r - l + 1;
  }
  return longest;
}

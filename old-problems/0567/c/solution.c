#include <stdbool.h>
#include <string.h>

bool checkInclusion(char* s1, char* s2) {
  int freqs1[26] = {0};
  int s1Len = 0;
  while (s1[s1Len] != 0) {
    ++freqs1[s1[s1Len] - 'a'];
    ++s1Len;
  }

  int freqs2[26] = {0};
  int s2Len = strlen(s2);
  for (int l = 0, r = 0; r < s2Len; ++r) {
    const char c = s2[r] - 'a';
    ++freqs2[c];
    while (l <= r && freqs2[c] > freqs1[c]) {
      --freqs2[s2[l] - 'a'];
      ++l;
    }
    if (r - l + 1 == s1Len) return true;
  }

  return false;
}

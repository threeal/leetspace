#include <stdbool.h>
#include <string.h>

bool buddyStrings(char* s, char* goal) {
  const int sLen = strlen(s);
  const int goalLen = strlen(goal);
  if (sLen != goalLen) return false;

  int freqs[26] = {0};
  for (int i = 0; i < sLen; ++i) {
    if (s[i] == goal[i]) {
      ++freqs[s[i] - 'a'];
      continue;
    }

    for (int j = i + 1; j < sLen; ++j) {
      if (s[j] == goal[j]) continue;
      if (s[i] != goal[j] || s[j] != goal[i]) return false;
      for (int k = j + 1; k < sLen; ++k) {
        if (s[k] != goal[k]) return false;
      }
      return true;
    }
    return false;
  }

  for (int i = 0; i < 26; ++i) {
    if (freqs[i] >= 2) return true;
  }

  return false;
}

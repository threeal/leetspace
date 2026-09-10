#include <stdbool.h>
#include <string.h>

bool checkStrings(char* s1, char* s2) {
  const int s1Len = strlen(s1);
  int freqs[26] = {0};
  for (int i = 0; i < 2; ++i) {
    for (int j = i; j < s1Len; j += 2) {
      ++freqs[s1[j] - 'a'];
      --freqs[s2[j] - 'a'];
    }

    for (int j = 0; j < 26; ++j) {
      if (freqs[j] != 0) return false;
    }
  }
  return true;
}

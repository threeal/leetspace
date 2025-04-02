#include <string.h>

int* partitionLabels(char* s, int* returnSize) {
  int allFreqs[26] = {0};

  const int sLen = strlen(s);
  for (int i = 0; i < sLen; ++i) ++allFreqs[s[i] - 'a'];

  int freqs[26] = {0};
  int missing = 0;

  static int output[26];
  int outputSize = 0;

  for (int l = 0, r = 0; r < sLen; ++r) {
    ++freqs[s[r] - 'a'];
    if (freqs[s[r] - 'a'] == allFreqs[s[r] - 'a']) {
      if (freqs[s[r] - 'a'] != 1) --missing;
    } else {
      if (freqs[s[r] - 'a'] == 1) ++missing;
    }

    if (missing == 0) {
      output[outputSize++] = r - l + 1;
      l = r + 1;
    }
  }

  *returnSize = outputSize;
  return output;
}

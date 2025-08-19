#include <limits.h>

int maxDifference(char* s) {
  int freqs[26] = {0};
  for (char* c = s; *c != 0; ++c) ++freqs[*c - 'a'];

  int even = INT_MAX;
  int odd = INT_MIN;

  for (int i = 0; i < 26; ++i) {
    if (freqs[i] > 0) {
      if (freqs[i] % 2 == 0) {
        if (freqs[i] < even) even = freqs[i];
      } else {
        if (freqs[i] > odd) odd = freqs[i];
      }
    }
  }

  return odd - even;
}

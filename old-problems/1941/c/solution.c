#include <stdbool.h>

bool areOccurrencesEqual(char* s) {
  char freqs[26] = {0};

  for (char* c = s; *c != 0; ++c) ++freqs[*c - 'a'];

  for (int i = 0; i < 26; ++i) {
    if (freqs[i] != 0) {
      const int freq = freqs[i];
      for (int j = i + 1; j < 26; ++j) {
        if (freqs[j] != 0 && freqs[j] != freq) return false;
      }
      return true;
    }
  }

  return true;
}

#include <stdlib.h>

char* robotWithString(char* s) {
  int freqs[26] = {0};
  int slen = 0;
  while (s[slen] != 0) {
    ++freqs[s[slen] - 'a'];
    ++slen;
  }

  char smallC = 'a';
  while (freqs[smallC - 'a'] == 0) ++smallC;

  int n = 0;
  char* t = malloc(slen * sizeof(char));
  int tlen = 0;

  for (int i = 0; i < slen; ++i) {
    --freqs[s[i] - 'a'];
    if (s[i] == smallC) {
      s[n++] = smallC;
      while (smallC <= 'z' && freqs[smallC - 'a'] == 0) {
        ++smallC;
        while (tlen > 0 && t[tlen - 1] <= smallC) {
          s[n++] = t[--tlen];
        }
      }
    } else {
      t[tlen++] = s[i];
    }
  }

  while (tlen > 0) {
    s[n++] = t[--tlen];
  }

  free(t);
  return s;
}

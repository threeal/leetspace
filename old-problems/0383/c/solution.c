#include <stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {
  int freqs[26] = {0};
  for (char* c = ransomNote; *c != 0; ++c) ++freqs[*c - 'a'];
  for (char* c = magazine; *c != 0; ++c) --freqs[*c - 'a'];

  for (int i = 0; i < 26; ++i) {
    if (freqs[i] > 0) return false;
  }

  return true;
}

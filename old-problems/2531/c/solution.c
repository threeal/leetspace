#include <stdbool.h>

bool isItPossible(char* word1, char* word2) {
  int freq1[26] = {0};
  while (*word1 != 0) {
    ++freq1[*word1 - 'a'];
    ++word1;
  }

  int freq2[26] = {0};
  while (*word2 != 0) {
    ++freq2[*word2 - 'a'];
    ++word2;
  }

  int distinct1 = 0;
  for (int i = 25; i >= 0; --i) {
    if (freq1[i] > 0) ++distinct1;
  }

  int distinct2 = 0;
  for (int i = 25; i >= 0; --i) {
    if (freq2[i] > 0) ++distinct2;
  }

  for (int i = 25; i >= 0; --i) {
    if (freq1[i] == 0) continue;
    if (--freq1[i] == 0) --distinct1;
    for (int j = 25; j >= 0; --j) {
      if (freq2[j] == 0) continue;
      if (++freq2[i] == 1) ++distinct2;
      if (--freq2[j] == 0) --distinct2;
      if (++freq1[j] == 1) ++distinct1;
      if (distinct1 == distinct2) return true;
      if (--freq1[j] == 0) --distinct1;
      if (++freq2[j] == 1) ++distinct2;
      if (--freq2[i] == 0) --distinct2;
    }
    if (++freq1[i] == 1) ++distinct1;
  }

  return false;
}

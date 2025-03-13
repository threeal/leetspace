#include <string.h>

int minimumRecolors(char* blocks, int k) {
  const int blocksLen = strlen(blocks);

  int freq = 0;
  for (int i = 0; i < k; ++i) {
    if (blocks[i] == 'W') ++freq;
  }

  int minFreq = freq;
  for (int i = k; i < blocksLen; ++i) {
    if (blocks[i] == 'W') ++freq;
    if (blocks[i - k] == 'W') --freq;
    if (freq < minFreq) minFreq = freq;
  }

  return minFreq;
}

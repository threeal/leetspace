#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool hasAllCodes(char* s, int k) {
  const int sLen = strlen(s);
  if (sLen < k) return false;

  const int existsLen = 1 << k;
  uint8_t* exists = malloc((existsLen / 8 + 1) * sizeof(uint8_t));
  memset(exists, 0, (existsLen / 8 + 1) * sizeof(uint8_t));
  int existsCount = 0;

  uint32_t mask = 1;
  mask = (mask << k) - 1;

  uint32_t code = 0;
  for (int i = 0; i < k; ++i) {
    code <<= 1;
    if (s[i] == '1') code |= 1;
  }

  const uint32_t idx = code & mask;
  exists[idx / 8] |= 1 << (idx % 8);
  ++existsCount;

  for (int i = k; i < sLen; ++i) {
    code <<= 1;
    if (s[i] == '1') code |= 1;
    const uint32_t idx = code & mask;
    if ((exists[idx / 8] & (1 << (idx % 8))) == 0) {
      exists[idx / 8] |= 1 << (idx % 8);
      if (++existsCount == existsLen) {
        free(exists);
        return true;
      }
    }
  }

  free(exists);
  return false;
}

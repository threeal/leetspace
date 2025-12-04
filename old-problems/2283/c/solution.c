#include <stdbool.h>

bool digitCount(char* num) {
  char freqs[10] = {0};
  for (char* c = num; *c != 0; ++c) ++freqs[*c - '0'];
  for (int i = 0; num[i] != 0; ++i) {
    if (num[i] - '0' != freqs[i]) return false;
  }
  return true;
}

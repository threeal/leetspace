#include <string.h>

int minimumDeletions(char* s) {
  int deletions = 0;
  int aCount = 0;
  for (int i = strlen(s) - 2; i >= 0; --i) {
    if (s[i] == 'b') ++deletions;
    if (s[i + 1] == 'a') ++aCount;
    if (aCount < deletions) deletions = aCount;
  }
  return deletions;
}

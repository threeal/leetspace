#include <string.h>

int countMatches(
    char*** items, int itemsSize, int* itemsColSize,
    char* ruleKey, char* ruleValue) {
  (void)itemsColSize;
  int count = 0;
  int j = ruleKey[0] == 't' ? 0 : (ruleKey[0] == 'c' ? 1 : 2);
  for (int i = 0; i < itemsSize; ++i) {
    if (strcmp(items[i][j], ruleValue) == 0) ++count;
  }
  return count;
}

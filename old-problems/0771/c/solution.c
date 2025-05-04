#include <stdbool.h>

int numJewelsInStones(char* jewels, char* stones) {
  bool isJewel[58] = {false};
  for (char* c = jewels; *c != 0; ++c) isJewel[*c - 'A'] = true;

  int count = 0;
  for (char* c = stones; *c != 0; ++c) {
    if (isJewel[*c - 'A']) ++count;
  }

  return count;
}

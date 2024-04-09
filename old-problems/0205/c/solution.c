#include <stdbool.h>
#include <string.h>

int sMap[128];
int tMap[128];

bool isIsomorphic(char* s, char* t) {
  memset(sMap, 0, 128 * sizeof(int));
  memset(tMap, 0, 128 * sizeof(int));

  for (int i = 0; s[i] != 0; ++i) {
    if (*(sMap + s[i]) != *(tMap + t[i])) return false;
    *(sMap + s[i]) = i + 1;
    *(tMap + t[i]) = i + 1;
  }

  return true;
}

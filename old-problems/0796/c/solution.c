#include <stdbool.h>
#include <string.h>

bool compare(char* a, char* b, int bSize);

bool rotateString(char* s, char* goal) {
  int sLen = strlen(s);
  int goalLen = strlen(goal);
  if (sLen != goalLen) return false;

  for (int i = sLen - 1; i >= 0; --i) {
    if (!compare(s + i, goal, sLen - i)) continue;
    if (!compare(s, goal + sLen - i, i)) continue;
    return true;
  }

  return false;
}

bool compare(char* a, char* b, int bSize) {
  for (int i = bSize - 1; i >= 0; --i) {
    if (a[i] != b[i]) return false;
  }

  return true;
}

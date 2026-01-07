#include <stdbool.h>
#include <string.h>

bool checkDistances(char* s, int* distance, int distanceSize) {
  (void)distanceSize;
  const int sLen = strlen(s);
  for (int i = 0; i < sLen; ++i) {
    if (distance[s[i] - 'a'] != -1) {
      const int j = i + distance[s[i] - 'a'] + 1;
      if (j >= sLen || s[i] != s[j]) return false;
      distance[s[i] - 'a'] = -1;
    }
  }
  return true;
}

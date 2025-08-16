#include <string.h>

char* smallestEquivalentString(char* s1, char* s2, char* baseStr) {
  int map[26];
  for (int i = 0; i < 26; ++i) map[i] = i;

  const int s1Len = strlen(s1);
  for (int i = 0; i < s1Len; ++i) {
    int c1 = s1[i] - 'a';
    while (map[c1] != c1) c1 = map[c1];

    int c2 = s2[i] - 'a';
    while (map[c2] != c2) c2 = map[c2];

    if (c1 != c2) {
      if (c1 < c2) {
        map[c2] = c1;
      } else {
        map[c1] = c2;
      }
    }
  }

  const int baseStrLen = strlen(baseStr);
  for (int i = 0; i < baseStrLen; ++i) {
    int c = baseStr[i] - 'a';
    while (map[c] != c) c = map[c];

    baseStr[i] = 'a' + c;
  }

  return baseStr;
}

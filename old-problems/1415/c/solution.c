#include <stdlib.h>
#include <string.h>

void findHappyString(char* s, int n, int i, int* k);

char* getHappyString(int n, int k) {
  char* s = malloc((n + 1) * sizeof(char));
  memset(s, 'a', n * sizeof(char));
  s[n] = '\0';

  findHappyString(s, n, 0, &k);
  return k == 0 ? s : "";
}

void findHappyString(char* s, int n, int i, int* k) {
  for (char c = 'a'; c <= 'c'; ++c) {
    if (i > 0 && s[i - 1] == c) continue;
    s[i] = c;
    if (i + 1 < n) {
      findHappyString(s, n, i + 1, k);
    } else {
      --(*k);
    }
    if (*k == 0) return;
  }
}

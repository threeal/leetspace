#include <string.h>

char* reverseByType(char* s) {
  const int sLen = strlen(s);
  int l = 0, rc = sLen - 1, rs = sLen - 1;
  while (l < rc || l < rs) {
    if (s[l] >= 'a') {
      while (l < rc && s[rc] < 'a') --rc;
      if (l < rc) {
        const char temp = s[l];
        s[l] = s[rc];
        s[rc] = temp;
        --rc;
      }
    } else {
      while (l < rs && s[rs] >= 'a') --rs;
      if (l < rs) {
        const char temp = s[l];
        s[l] = s[rs];
        s[rs] = temp;
        --rs;
      }
    }
    ++l;
  }

  return s;
}

#include <string.h>

typedef struct {
  int a;
  int b;
  int c;
} specials_t;

int maximumLength(char* s) {
  specials_t specials[26];
  memset(specials, 0, 26 * sizeof(specials_t));

  int prev = 0;
  const int slen = strlen(s);
  for (int i = 1; i <= slen; ++i) {
    if (s[i] != s[i - 1]) {
      const int j = s[i - 1] - 'a';
      if (i - prev > specials[j].a) {
        specials[j].c = specials[j].b;
        specials[j].b = specials[j].a;
        specials[j].a = i - prev;
      } else if (i - prev > specials[j].b) {
        specials[j].c = specials[j].b;
        specials[j].b = i - prev;
      } else if (i - prev > specials[j].c) {
        specials[j].c = i - prev;
      }
      prev = i;
    }
  }

  int max = 0;
  for (int i = 0; i < 26; ++i) {
    if (specials[i].a > 0) {
      if (specials[i].a - 2 > max) max = specials[i].a - 2;

      if (specials[i].b > 0) {
        if (specials[i].a == specials[i].b) {
          if (specials[i].a - 1 > max) max = specials[i].a - 1;
        } else {
          if (specials[i].b > max) max = specials[i].b;
        }

        if (specials[i].c > 0) {
          if (specials[i].c > max) max = specials[i].c;
        }
      }
    }
  }

  return max == 0 ? -1 : max;
}

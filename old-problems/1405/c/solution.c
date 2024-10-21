#include <stdlib.h>

char* longestDiverseString(int a, int b, int c) {
  char* s = malloc((a + b + c + 1) * sizeof(char));
  int i = 0;

  if (a >= b && a >= c) {
    if (a == 1) {
      s[i++] = 'a';
      a = 0;
    } else {
      s[i++] = 'a';
      s[i++] = 'a';
      a -= 2;
    }
  } else if (b >= a && b >= c) {
    if (b == 1) {
      s[i++] = 'b';
      b = 0;
    } else {
      s[i++] = 'b';
      s[i++] = 'b';
      b -= 2;
    }
  } else {
    if (c == 1) {
      s[i++] = 'c';
      c = 0;
    } else {
      s[i++] = 'c';
      s[i++] = 'c';
      c -= 2;
    }
  }

  while (a > 0 || b > 0 || c > 0) {
    if (s[i - 1] == 'a') {
      if (b >= c) {
        if (b == 0) break;
        if (b >= 2 && b + c >= a) {
          s[i++] = 'b';
          s[i++] = 'b';
          b -= 2;
        } else {
          s[i++] = 'b';
          --b;
        }
      } else {
        if (c == 0) break;
        if (c >= 2 && b + c >= a) {
          s[i++] = 'c';
          s[i++] = 'c';
          c -= 2;
        } else {
          s[i++] = 'c';
          --c;
        }
      }
    } else if (s[i - 1] == 'b') {
      if (a >= c) {
        if (a == 0) break;
        if (a >= 2 && a + c >= b) {
          s[i++] = 'a';
          s[i++] = 'a';
          a -= 2;
        } else {
          s[i++] = 'a';
          --a;
        }
      } else {
        if (c == 0) break;
        if (c >= 2 && a + c >= b) {
          s[i++] = 'c';
          s[i++] = 'c';
          c -= 2;
        } else {
          s[i++] = 'c';
          --c;
        }
      }
    } else {
      if (a >= b) {
        if (a == 0) break;
        if (a >= 2 && a + b >= c) {
          s[i++] = 'a';
          s[i++] = 'a';
          a -= 2;
        } else {
          s[i++] = 'a';
          --a;
        }
      } else {
        if (b == 0) break;
        if (b >= 2 && a + b >= c) {
          s[i++] = 'b';
          s[i++] = 'b';
          b -= 2;
        } else {
          s[i++] = 'b';
          --b;
        }
      }
    }
  }

  s[i] = 0;
  return s;
}

#include <stdlib.h>
#include <string.h>

static int findGcd(int a, int b);
static int print(char* str, int i, int num);

char** simplifiedFractions(int n, int* returnSize) {
  char** output = malloc((n * (n - 1) / 2) * sizeof(char*));
  int outputSize = 0;

  char* str = malloc(7 * sizeof(char));
  for (int a = 1; a < n; ++a) {
    int ai = print(str, 0, a);
    str[ai++] = '/';
    for (int b = a + 1; b <= n; ++b) {
      if (findGcd(a, b) == 1) {
        const int bi = print(str, ai, b);
        char* substr = malloc((bi + 1) * sizeof(char));
        memcpy(substr, str, bi * sizeof(char));
        substr[bi] = 0;
        output[outputSize++] = substr;
      }
    }
  }

  free(str);

  *returnSize = outputSize;
  return output;
}

static int findGcd(int a, int b) {
  while (b) {
    const int tmp = a % b;
    a = b;
    b = tmp;
  }
  return a < 0 ? -a : a;
}

static int print(char* str, int i, int num) {
  if (num < 10) {
    str[i] = '0' + num;
    return i + 1;
  } else if (num < 100) {
    str[i] = '0' + num / 10;
    str[i + 1] = '0' + num % 10;
    return i + 2;
  } else {
    str[i] = '0' + num / 100;
    str[i + 1] = '0' + (num / 10) % 10;
    str[i + 2] = '0' + num % 10;
    return i + 3;
  }
}

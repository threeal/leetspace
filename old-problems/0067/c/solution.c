#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
  int aSize = strlen(a);
  int bSize = strlen(b);
  if (aSize < bSize) {
    char* temp = a;
    int tempSize = aSize;

    a = b;
    aSize = bSize;

    b = temp;
    bSize = tempSize;
  }

  bool remainder = false;
  for (int i = aSize - 1, j = bSize - 1; j >= 0; --i, --j) {
    switch (a[i]) {
      case '0':
        switch (b[j]) {
          case '0':
            if (remainder) {
              remainder = false;
              a[i] = '1';
            }
            break;

          case '1':
            if (!remainder) {
              a[i] = '1';
            }
            break;
        }
        break;

      case '1':
        switch (b[j]) {
          case '0':
            if (remainder) {
              a[i] = '0';
            }
            break;

          case '1':
            if (!remainder) {
              remainder = true;
              a[i] = '0';
            }
            break;
        }
        break;
    }
  }

  for (int i = aSize - bSize - 1; i >= 0 && remainder; --i) {
    switch (a[i]) {
      case '0':
        a[i] = '1';
        remainder = false;
        break;

      case '1':
        a[i] = '0';
        break;
    }
  }

  if (remainder) {
    b = malloc((aSize + 2) * sizeof(char));
    b[0] = '1';
    memcpy(b + 1, a, (aSize + 1) * sizeof(char));
    a = b;
  }

  return a;
}

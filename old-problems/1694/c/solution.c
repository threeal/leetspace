#include <stdlib.h>

char* reformatNumber(char* number) {
  int l = 0;
  for (int i = 0; number[i] != 0; ++i) {
    if (number[i] >= '0') number[l++] = number[i];
  }

  int r = 0;
  switch (l % 3) {
    case 0:
      r = l + l / 3 - 1;
      number = realloc(number, (r + 1) * sizeof(char));
      number[r] = 0;
      number[--r] = number[--l];
      number[--r] = number[--l];
      number[--r] = number[--l];
      break;

    case 1:
      r = l + (l - 4) / 3 + 1;
      number = realloc(number, (r + 1) * sizeof(char));
      number[r] = 0;
      number[--r] = number[--l];
      number[--r] = number[--l];
      number[--r] = '-';
      number[--r] = number[--l];
      number[--r] = number[--l];
      break;

    case 2:
      r = l + (l - 2) / 3;
      number = realloc(number, (r + 1) * sizeof(char));
      number[r] = 0;
      number[--r] = number[--l];
      number[--r] = number[--l];
  }

  while (l > 0) {
    number[--r] = '-';
    number[--r] = number[--l];
    number[--r] = number[--l];
    number[--r] = number[--l];
  }

  return number;
}

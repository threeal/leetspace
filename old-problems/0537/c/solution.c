#include <stdbool.h>
#include <stdlib.h>

static int parseNumber(char* s, int* i, char c);

char* complexNumberMultiply(char* num1, char* num2) {
  int i = 0;
  const int real1 = parseNumber(num1, &i, '+');

  ++i;
  const int imagine1 = parseNumber(num1, &i, 'i');

  i = 0;
  const int real2 = parseNumber(num2, &i, '+');

  ++i;
  const int imagine2 = parseNumber(num2, &i, 'i');

  int real = real1 * real2 - imagine1 * imagine2;
  int imagine = real1 * imagine2 + real2 * imagine1;

  int strSize = 3;

  bool isRealNeg = false;
  if (real < 0) {
    ++strSize;
    isRealNeg = true;
    real = -real;
  }

  int realExp = 1;
  if (real == 0) {
    ++strSize;
  } else {
    while (realExp <= real) {
      ++strSize;
      realExp *= 10;
    }
  }

  bool isImagineNeg = false;
  if (imagine < 0) {
    ++strSize;
    isImagineNeg = true;
    imagine = -imagine;
  }

  int imagineExp = 1;
  if (imagine == 0) {
    ++strSize;
  } else {
    while (imagineExp <= imagine) {
      ++strSize;
      imagineExp *= 10;
    }
  }

  char* str = malloc(strSize * sizeof(char));
  strSize = 0;

  if (isRealNeg) str[strSize++] = '-';
  if (real == 0) {
    str[strSize++] = '0';
  } else {
    while ((realExp /= 10) != 0) {
      str[strSize++] = '0' + (real / realExp) % 10;
    }
  }

  str[strSize++] = '+';
  if (isImagineNeg) str[strSize++] = '-';
  if (imagine == 0) {
    str[strSize++] = '0';
  } else {
    while ((imagineExp /= 10) != 0) {
      str[strSize++] = '0' + (imagine / imagineExp) % 10;
    }
  }

  str[strSize++] = 'i';
  str[strSize] = 0;

  return str;
}

static int parseNumber(char* s, int* i, char c) {
  bool isNeg = false;
  if (s[*i] == '-') {
    isNeg = true;
    ++(*i);
  }

  int num = 0;
  while (s[*i] != c) {
    num = num * 10 + s[*i] - '0';
    ++(*i);
  }

  return isNeg ? -num : num;
}

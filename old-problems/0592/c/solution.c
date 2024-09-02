#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int findGcd(int a, int b);

char* fractionAddition(char* expression) {
  bool isNegative = false;
  int prevNumerator = 0;
  int prevDenominator = 1;

  char* c = expression;
  if (*c == '-') {
    isNegative = true;
    ++c;
  }

  while (*c != 0) {
    int numerator = 0;
    while (*c >= '0') {
      numerator = numerator * 10 + (*c - '0');
      ++c;
    }
    ++c;

    int denominator = 0;
    while (*c >= '0') {
      denominator = denominator * 10 + (*c - '0');
      ++c;
    }

    prevNumerator = isNegative
        ? prevNumerator * denominator - numerator * prevDenominator
        : prevNumerator * denominator + numerator * prevDenominator;
    prevDenominator *= denominator;

    const int gcd = findGcd(prevNumerator, prevDenominator);
    prevNumerator /= gcd;
    prevDenominator /= gcd;

    if (*c != 0) {
      isNegative = *c == '-';
      ++c;
    }
  }

  char* buf = malloc(32 * sizeof(char));
  sprintf(buf, "%d/%d", prevNumerator, prevDenominator);
  return buf;
}

int findGcd(int a, int b) {
  int tmp;
  while (b) {
    tmp = a % b;
    a = b;
    b = tmp;
  }
  return a < 0 ? -a : a;
}

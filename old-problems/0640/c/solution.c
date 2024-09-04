#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* solveEquation(char* equation) {
  int coefficient = 0, constant = 0;
  char* c = equation;
  while (*c != '=') {
    bool negative = false;
    if (*c == '+') ++c;
    if (*c == '-') {
      negative = true;
      ++c;
    }

    if (*c == 'x') {
      coefficient += negative ? -1 : 1;
      ++c;
      continue;
    }

    int num = 0;
    while (*c >= '0' && *c <= '9') {
      num = num * 10 + *c - '0';
      ++c;
    }
    if (negative) num = -num;

    if (*c == 'x') {
      coefficient += num;
      ++c;
    } else {
      constant -= num;
    }
  }

  ++c;
  while (*c != 0) {
    bool negative = false;
    if (*c == '+') ++c;
    if (*c == '-') {
      negative = true;
      ++c;
    }

    if (*c == 'x') {
      coefficient -= negative ? -1 : 1;
      ++c;
      continue;
    }

    int num = 0;
    while (*c >= '0' && *c <= '9') {
      num = num * 10 + *c - '0';
      ++c;
    }
    if (negative) num = -num;

    if (*c == 'x') {
      coefficient -= num;
      ++c;
    } else {
      constant += num;
    }
  }

  if (coefficient == 0) {
    return constant == 0 ? "Infinite solutions" : "No solution";
  }

  char* output = malloc(15 * sizeof(char));
  sprintf(output, "x=%d", constant / coefficient);
  return output;
}

#include <stdbool.h>

static int calculateExpression(char** c);

int calculate(char* s) {
  return calculateExpression(&s);
}

static int calculateExpression(char** c) {
  int sum = 0;
  bool negative = false;
  while (**c == ' ') ++(*c);
  while (**c != 0) {
    if (**c >= '0') {
      int num = 0;
      while (**c >= '0') {
        num = num * 10 + (**c - '0');
        ++(*c);
      }
      if (negative) {
        sum -= num;
        negative = false;
      } else {
        sum += num;
      }
    } else if (**c == '+') {
      ++(*c);
    } else if (**c == '-') {
      ++(*c);
      negative = true;
    } else if (**c == '(') {
      ++(*c);
      if (negative) {
        sum -= calculateExpression(c);
        negative = false;
      } else {
        sum += calculateExpression(c);
      }
    } else if (**c == ')') {
      ++(*c);
      break;
    }
    while (**c == ' ') ++(*c);
  }
  return sum;
}

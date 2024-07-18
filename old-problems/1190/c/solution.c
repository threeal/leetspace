#include <stdlib.h>

char* reverseParentheses(char* s) {
  // Reverse substrings based on the parentheses.
  int openersMaxSize = 32;
  int openersSize = 0;
  char** openers = malloc(openersMaxSize * sizeof(char*));

  for (char* c = s; *c != 0; ++c) {
    switch (*c) {
      case '(':
        openers[openersSize] = c;
        if (++openersSize >= openersMaxSize) {
          openersMaxSize *= 8;
          openers = realloc(openers, openersMaxSize * sizeof(char*));
        }
        break;

      case ')':
        --openersSize;
        char* left = openers[openersSize] + 1;
        char* right = c - 1;
        while (left < right) {
          char tmp = *left;
          *left = *right;
          *right = tmp;
          ++left;
          --right;
        }
    }
  }
  free(openers);

  // Remove any parentheses from the string.
  char* out = s;
  for (char* c = s; *c != 0; ++c) {
    switch (*c) {
      case ')':
      case '(':
        break;

      default:
        *out = *c;
        ++out;
    }
  }
  *out = 0;

  return s;
}

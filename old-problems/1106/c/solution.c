#include <stdbool.h>

static bool parse(char** c);

bool parseBoolExpr(char* expression) {
  char* c = expression;
  return parse(&c);
}

static bool parse(char** c) {
  if (**c == 't') {
    ++(*c);
    return true;
  }

  if (**c == 'f') {
    ++(*c);
    return false;
  }

  if (**c == '!') {
    *c += 2;
    const bool b = !parse(c);
    ++(*c);
    return b;
  }

  if (**c == '&') {
    bool b = true;
    ++(*c);
    while (**c != ')') {
      ++(*c);
      b &= parse(c);
    }
    ++(*c);
    return b;
  }

  bool b = false;
  ++(*c);
  while (**c != ')') {
    ++(*c);
    b |= parse(c);
  }
  ++(*c);
  return b;
}

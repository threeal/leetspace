char* removeOuterParentheses(char* s) {
  int level = 0, n = 0;
  for (char* c = s; *c != 0; ++c) {
    if (*c == '(') {
      if (++level != 1) s[n++] = '(';
    } else {
      if (--level != 0) s[n++] = ')';
    }
  }
  s[n] = 0;
  return s;
}

char* finalString(char* s) {
  char* c = s;
  char* out = s;
  while (*c != 0) {
    if (*c == 'i') {
      char* l = s;
      char* r = out - 1;
      while (l < r) {
        const char temp = *l;
        *l = *r;
        *r = temp;
        ++l;
        --r;
      }
    } else {
      *out = *c;
      ++out;
    }
    ++c;
  }
  *out = 0;
  return s;
}

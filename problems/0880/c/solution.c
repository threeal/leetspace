char decode(char* s, unsigned int k);

char* decodeAtIndex(char* s, int k) {
  s[0] = decode(s, k - 1);
  s[1] = 0;
  return s;
}

char decode(char* s, unsigned int k) {
  unsigned int i = 0;
  char* c = s;
  while (*c != 0) {
    if (*c > '9') {
      if (i++ == k) {
        return *c;
      }
    } else {
      const unsigned int repeat = *c - '0';
      if (k < i * repeat) {
        return decode(s, k % i);
      } else {
        i *= repeat;
      }
    }
    ++c;
  }
  return 0;
}

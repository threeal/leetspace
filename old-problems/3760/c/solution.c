int maxDistinct(char* s) {
  unsigned int flag = 0;
  for (char* c = s; *c != 0; ++c) {
    flag |= 1 << (*c - 'a');
  }
  return __builtin_popcount(flag);
}

int numberOfSpecialChars(char* word) {
  unsigned int lower = 0, upper = 0;
  while (*word != 0) {
    if (*word >= 'a') {
      if ((upper & (1 << (*word - 'a'))) == 0) {
        lower |= 1 << (*word - 'a');
      } else {
        lower &= ~(1 << (*word - 'a'));
      }
    } else {
      upper |= 1 << (*word - 'A');
    }
    ++word;
  }
  return __builtin_popcount(lower & upper);
}

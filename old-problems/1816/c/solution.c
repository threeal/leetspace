char* truncateSentence(char* s, int k) {
  for (int i = 0; s[i] != 0; ++i) {
    if (s[i] == ' ' && --k == 0) {
      s[i] = 0;
      break;
    }
  }
  return s;
}

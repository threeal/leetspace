int minimumLength(char* s) {
  int freqs[26] = {0};
  while (*s != 0) {
    ++freqs[*s - 'a'];
    ++s;
  }

  int len = 0;
  for (int i = 0; i < 26; ++i) {
    if (freqs[i] == 0) continue;
    len += freqs[i] % 2 == 0 ? 2 : 1;
  }

  return len;
}

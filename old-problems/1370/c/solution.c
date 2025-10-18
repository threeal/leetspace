char* sortString(char* s) {
  int freqs[26] = {0};
  for (int i = 0; s[i] != 0; ++i) ++freqs[s[i] - 'a'];

  for (int i = 0; s[i] != 0;) {
    for (int j = 0; j < 26; ++j) {
      if (freqs[j] > 0) {
        s[i++] = 'a' + j;
        --freqs[j];
      }
    }

    for (int j = 25; j >= 0; --j) {
      if (freqs[j] > 0) {
        s[i++] = 'a' + j;
        --freqs[j];
      }
    }
  }

  return s;
}

int longestIdealString(char* s, int k) {
  int counts[26] = {0};

  while (*s != 0) {
    *s -= 'a';
    const int count = counts[*s] + 1;

    char n = *s + k;
    if (n > 25) n = 25;
    for (char i = *s >= k ? *s - k : 0; i <= n; ++i) {
      if (count > counts[i]) counts[i] = count;
    }

    ++s;
  }

  for (char i = 1; i < 26; ++i) {
    if (counts[i] > counts[0]) counts[0] = counts[i];
  }

  return counts[0];
}

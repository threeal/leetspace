int beautySum(char* s) {
  int n = 0;
  while (s[n] != 0) {
    s[n] -= 'a';
    ++n;
  }

  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int freqs[26] = {0};
    ++freqs[s[i]];

    char most = s[i], least = s[i];

    for (int j = i + 1; j < n; ++j) {
      ++freqs[s[j]];
      if (freqs[s[j]] > freqs[most]) most = s[j];
      if (s[j] == least) {
        for (char c = 0; c < 26; ++c) {
          if (freqs[c] != 0 && freqs[c] < freqs[least]) least = c;
        }
      } else if (freqs[s[j]] < freqs[least]) {
        least = s[j];
      }

      sum += freqs[most] - freqs[least];
    }
  }

  return sum;
}

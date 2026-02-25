char* majorityFrequencyGroup(char* s) {
  int freqs[26] = {0};
  for (char* c = s; *c != 0; ++c) ++freqs[*c - 'a'];

  int freqMembers[101] = {0};
  int majorFreq = 0;
  for (int i = 0; i < 26; ++i) {
    if (freqs[i] != 0) {
      ++freqMembers[freqs[i]];
      if (freqMembers[freqs[i]] > freqMembers[majorFreq] ||
          (freqMembers[freqs[i]] == freqMembers[majorFreq] && freqs[i] > majorFreq)) {
        majorFreq = freqs[i];
      }
    }
  }

  int n = 0;
  for (int i = 0; i < 26; ++i) {
    if (freqs[i] == majorFreq) s[n++] = 'a' + i;
  }

  s[n] = 0;
  return s;
}

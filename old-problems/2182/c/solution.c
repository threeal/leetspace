char* repeatLimitedString(char* s, int repeatLimit) {
  int freqs[26] = {0};
  for (int i = 0; s[i] != 0; ++i) {
    ++freqs[s[i] - 'a'];
  }

  int curr = 25;
  while (curr >= 0 && freqs[curr] == 0) --curr;

  int next = curr - 1;
  while (next >= 0 && freqs[next] == 0) --next;

  int i = 0;
  while (curr >= 0) {
    if (freqs[curr] > repeatLimit) {
      for (int k = repeatLimit; k > 0; --k, ++i) s[i] = 'a' + curr;
      freqs[curr] -= repeatLimit;

      if (next < 0) break;
      s[i] = 'a' + next;
      ++i;

      --freqs[next];
      while (next >= 0 && freqs[next] == 0) --next;
    } else {
      for (int k = freqs[curr]; k > 0; --k, ++i) s[i] = 'a' + curr;
      freqs[curr] = 0;

      curr = next;
      --next;
      while (next >= 0 && freqs[next] == 0) --next;
    }
  }

  s[i] = 0;
  return s;
}

int longestSubsequence(char* s, int k) {
  unsigned long long num = 0;
  int count = 0, maxCount = 0;
  while (*s != 0) {
    ++count;
    num = num << 1 | (*s == '0' ? 0 : 1);
    while (num > (unsigned long long)k) {
      num &= ~(1 << (63 - __builtin_clzll(num)));
      --count;
    }
    if (count > maxCount) maxCount = count;
    ++s;
  }
  return maxCount;
}

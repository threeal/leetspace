int concatenatedBinary(int n) {
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans = ((ans << (32 - __builtin_clz(i))) | i) % 1000000007;
  }
  return ans;
}

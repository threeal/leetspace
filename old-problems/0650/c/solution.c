int minSteps(int n) {
  int ans = 0;
  for (int i = 2; n > 1; ++i) {
    while (n > 1 && n % i == 0) {
      ans += i;
      n /= i;
    }
  }
  return ans;
}

int coinChange(int* coins, int coinsSize, int amount) {
  static int counts[10001];

  counts[0] = 0;
  for (int i = 1; i <= amount; ++i) counts[i] = 10000;

  for (int i = 0; i < coinsSize; ++i) {
    if (coins[i] <= amount) {
      counts[coins[i]] = 1;
      for (int l = 1, r = coins[i] + 1; r <= amount; ++l, ++r) {
        if (counts[l] + 1 < counts[r]) counts[r] = counts[l] + 1;
      }
    }
  }

  return counts[amount] <= amount ? counts[amount] : -1;
}

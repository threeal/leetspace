int coinChange(int* coins, int coinsSize, int amount) {
  return amount / coins[coinsSize - 1];
}

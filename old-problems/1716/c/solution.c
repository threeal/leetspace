int totalMoney(int n) {
  const int div = n / 7;
  const int mod = n % 7;
  return (div * (49 + 7 * div) + mod * (2 * div + mod + 1)) / 2;
}

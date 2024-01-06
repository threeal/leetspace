int buyChoco(int* prices, int pricesSize, int money) {
  // Determine the smallest between the first and the second price.
  int a = prices[0] < prices[1] ? prices[0] : prices[1];
  int b = prices[0] < prices[1] ? prices[1] : prices[0];

  // Iterate throught the rest of the prices two update the two smallest prices.
  for (int i = 2; i < pricesSize; ++i) {
    if (prices[i] >= b) continue;
    if (prices[i] < a) {
      b = a;
      a = prices[i];
    } else {
      b = prices[i];
    }
  }

  // If the total price is higher than the money, return the money instead.
  return a + b > money ? money : money - a - b;
}

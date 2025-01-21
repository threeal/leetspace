#include <stdlib.h>

int mincostTickets(int* days, int daysSize, int* costs, int costsSize) {
  (void)costsSize;

  int* prices = malloc(daysSize * sizeof(int));
  prices[0] = costs[0] < costs[1] ? costs[0] : costs[1];
  if (costs[2] < prices[0]) prices[0] = costs[2];

  for (int i = 1, i7 = 0, i30 = 0; i < daysSize; ++i) {
    while (days[i7] + 7 <= days[i]) ++i7;
    while (days[i30] + 30 <= days[i]) ++i30;

    const int price1 = costs[0] + prices[i - 1];
    const int price7 = costs[1] + (i7 > 0 ? prices[i7 - 1] : 0);
    const int price30 = costs[2] + (i30 > 0 ? prices[i30 - 1] : 0);

    prices[i] = price1 < price7 ? price1 : price7;
    if (price30 < prices[i]) prices[i] = price30;
  }

  return prices[daysSize - 1];
}

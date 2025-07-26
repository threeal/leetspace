#include <stdlib.h>

int candy(int* ratings, int ratingsSize) {
  int* candies = malloc(ratingsSize * sizeof(int));
  for (int i = 0; i < ratingsSize; ++i) candies[i] = 1;

  for (int i = 1; i < ratingsSize; ++i) {
    if (ratings[i] > ratings[i - 1]) {
      candies[i] = candies[i - 1] + 1;
    }
  }

  int total = candies[ratingsSize - 1];
  for (int i = ratingsSize - 1; i > 0; --i) {
    if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
      candies[i - 1] = candies[i] + 1;
    }
    total += candies[i - 1];
  }

  return total;
}

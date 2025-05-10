#include <stdbool.h>
#include <stdlib.h>

bool* kidsWithCandies(
    int* candies, int candiesSize, int extraCandies, int* returnSize) {
  int maxCandy = 0;
  for (int i = 0; i < candiesSize; ++i) {
    if (candies[i] > maxCandy) maxCandy = candies[i];
  }

  bool* output = malloc(candiesSize * sizeof(bool));
  for (int i = 0; i < candiesSize; ++i) {
    output[i] = candies[i] + extraCandies >= maxCandy;
  }

  *returnSize = candiesSize;
  return output;
}

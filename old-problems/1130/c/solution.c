#include <limits.h>
#include <stdlib.h>
#include <string.h>

struct val_cost_t {
  int val;
  int cost;
};

int mctFromLeafValues(int* arr, int arrSize) {
  struct val_cost_t** values = malloc(arrSize * sizeof(struct val_cost_t*));

  values[0] = malloc(arrSize * sizeof(struct val_cost_t));
  for (int i = 0; i < arrSize; ++i) {
    values[0][i].val = arr[i];
    values[0][i].cost = 0;
  }

  for (int i = 1; i < arrSize; ++i) {
    const int n = arrSize - i;
    values[i] = malloc(n * sizeof(struct val_cost_t));
    for (int j = 0; j < n; ++j) {
      int maxVal = 0, minCost = INT_MAX;
      for (int k = 0; k < i; ++k) {
        const struct val_cost_t left = values[k][j];
        const struct val_cost_t right = values[i - k - 1][j + k + 1];

        const int val = left.val >= right.val ? left.val : right.val;
        if (val > maxVal) maxVal = val;

        const int cost = left.cost + right.cost + left.val * right.val;
        if (cost < minCost) minCost = cost;
      }

      values[i][j].val = maxVal;
      values[i][j].cost = minCost;
    }
  }

  const int cost = values[arrSize - 1][0].cost;

  for (int i = 0; i < arrSize; ++i) free(values[i]);
  free(values);

  return cost;
}

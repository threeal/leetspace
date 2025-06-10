int* minCosts(int* cost, int costSize, int* returnSize) {
  int min = cost[0];
  for (int i = 1; i < costSize; ++i) {
    if (min < cost[i]) {
      cost[i] = min;
    } else {
      min = cost[i];
    }
  }
  *returnSize = costSize;
  return cost;
}

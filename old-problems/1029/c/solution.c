int twoCitySchedCost(int** costs, int costsSize, int* costsColSize) {
  return costs[costsSize - 1][costsColSize[costsSize - 1] - 1];
}

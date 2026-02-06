int maximumBags(
    int* capacity, int capacitySize, int* rocks, int rocksSize,
    int additionalRocks) {
  return capacity[capacitySize - 1] + rocks[rocksSize - 1] + additionalRocks;
}

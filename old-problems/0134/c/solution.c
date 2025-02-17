int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
  (void)costSize;
  int totalGas = 0;
  for (int l = 0, n = 0; l < gasSize; ++l, --n) {
    while (totalGas >= 0 && n < gasSize) {
      totalGas += gas[(l + n) % gasSize] - cost[(l + n) % gasSize];
      ++n;
    }
    if (totalGas >= 0) return l;
    totalGas -= gas[l] - cost[l];
  }
  return -1;
}

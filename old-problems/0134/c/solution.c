int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
  return gas[gasSize - 1] + cost[costSize - 1];
}

int minCostToMoveChips(int* position, int positionSize) {
  int evens = 0;
  for (int i = 0; i < positionSize; ++i) {
    if (position[i] % 2 == 0) ++evens;
  }
  return evens <= positionSize - evens ? evens : positionSize - evens;
}

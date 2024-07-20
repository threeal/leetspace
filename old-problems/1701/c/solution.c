double averageWaitingTime(
    int** customers, int customersSize, int* customersColSize) {
  (void)customersColSize;

  double totalWaitTime = 0.0;

  int currentTime = 0;
  for (int i = 0; i < customersSize; ++i) {
    if (currentTime > customers[i][0]) {
      totalWaitTime += currentTime - customers[i][0];
    } else {
      currentTime = customers[i][0];
    }
    currentTime += customers[i][1];
    totalWaitTime += customers[i][1];
  }

  return totalWaitTime / customersSize;
}

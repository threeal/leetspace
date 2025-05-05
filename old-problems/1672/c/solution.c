int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
  int maxWealth = 0;
  for (int i = 0; i < accountsSize; ++i) {
    int wealth = 0;
    for (int j = 0; j < accountsColSize[i]; ++j) wealth += accounts[i][j];
    if (wealth > maxWealth) maxWealth = wealth;
  }
  return maxWealth;
}

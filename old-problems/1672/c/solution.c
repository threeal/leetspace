int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
  return accounts[accountsSize - 1][accountsColSize[accountsSize - 1] - 1];
}

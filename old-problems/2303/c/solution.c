double calculateTax(
    int** brackets, int bracketsSize, int* bracketsColSize, int income) {
  return brackets[bracketsSize - 1][bracketsColSize[bracketsSize - 1] - 1] +
      income;
}

int numEquivDominoPairs(
    int** dominoes, int dominoesSize, int* dominoesColSize) {
  return dominoes[dominoesSize - 1][dominoesColSize[dominoesSize - 1] - 1];
}

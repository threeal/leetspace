int minTimeToReach(int** moveTime, int moveTimeSize, int* moveTimeColSize) {
  return moveTime[moveTimeSize - 1][moveTimeColSize[moveTimeSize - 1] - 1];
}

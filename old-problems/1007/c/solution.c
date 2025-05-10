int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
  return tops[topsSize - 1] + bottoms[bottomsSize - 1];
}

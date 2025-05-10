static int minDominoRotationsForNumber(
    int* tops, int* bottoms, int n, int num);

int minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize) {
  int rotations = minDominoRotationsForNumber(tops, bottoms, topsSize, tops[0]);
  if (rotations == -1 && tops[0] != bottoms[0]) {
    rotations = minDominoRotationsForNumber(
        tops, bottoms, bottomsSize, bottoms[0]);
  }
  return rotations;
}

static int minDominoRotationsForNumber(
    int* tops, int* bottoms, int n, int num) {
  int topFreqs = 0, bottomFreqs = 0;
  for (int i = 0; i < n; ++i) {
    if (tops[i] == num) {
      if (bottoms[i] != num) {
        ++topFreqs;
      }
    } else {
      if (bottoms[i] == num) {
        ++bottomFreqs;
      } else {
        return -1;
      }
    }
  }
  return topFreqs <= bottomFreqs ? topFreqs : bottomFreqs;
}

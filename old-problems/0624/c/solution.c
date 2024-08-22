int maxDistance(int** arrays, int arraysSize, int* arraysColSize) {
  int distance = 0;

  int prevMin = 10001;
  int prevMax = -10001;

  for (int i = arraysSize - 1; i >= 0; --i) {
    const int min = arrays[i][0];
    const int max = arrays[i][arraysColSize[i] - 1];

    if (prevMax - min > distance) distance = prevMax - min;
    if (max - prevMin > distance) distance = max - prevMin;

    if (min < prevMin) prevMin = min;
    if (max > prevMax) prevMax = max;
  }

  return distance;
}

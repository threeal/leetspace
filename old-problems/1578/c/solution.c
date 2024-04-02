int minCost(char* colors, int* neededTime, int neededTimeSize) {
  (void)neededTimeSize;
  int total = 0;

  int left = 0;
  int right = 1;

  while (colors[right] != 0) {
    if (colors[left] != colors[right]) {
      int largest = 0;
      for (int i = left; i < right; ++i) {
        if (neededTime[i] > largest) largest = neededTime[i];
        total += neededTime[i];
      }
      total -= largest;
      left = right;
    }
    ++right;
  }

  int largest = 0;
  for (int i = left; i < right; ++i) {
    if (neededTime[i] > largest) largest = neededTime[i];
    total += neededTime[i];
  }
  total -= largest;

  return total;
}

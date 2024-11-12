int largestCombination(int* candidates, int candidatesSize) {
  int counts[24] = {0};
  for (int i = 0; i < candidatesSize; ++i) {
    for (int j = 0; j < 24; ++j) {
      if ((candidates[i] & (1 << j)) > 0) ++counts[j];
    }
  }

  int max = counts[0];
  for (int i = 1; i < 24; ++i) {
    if (counts[i] > max) max = counts[i];
  }

  return max;
}

int maxScoreSightseeingPair(int* values, int valuesSize) {
  int maxScore = 0, maxVal = values[0];
  for (int i = 1; i < valuesSize; ++i) {
    --maxVal;
    if (maxVal + values[i] > maxScore) maxScore = maxVal + values[i];
    if (values[i] >= maxVal) maxVal = values[i];
  }
  return maxScore;
}

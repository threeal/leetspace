int numberOfArrays(
    int* differences, int differencesSize, int lower, int upper) {
  long long val = 0, min = 0, max = 0;
  for (int i = 0; i < differencesSize; ++i) {
    val += differences[i];
    if (val > max) max = val;
    if (val < min) min = val;
  }
  return upper - lower >= max - min ? 1 + (upper - lower) - (max - min) : 0;
}

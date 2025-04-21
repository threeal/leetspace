int numberOfArrays(
    int* differences, int differencesSize, int lower, int upper) {
  return differences[differencesSize - 1] + upper - lower;
}

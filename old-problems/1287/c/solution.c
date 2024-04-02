int findSpecialInteger(int* arr, int arrSize) {
  int* a = arr;
  int* b = a + arrSize / 4;
  while (1) {
    if (*a == *b) return *a;
    ++a;
    ++b;
  }
  return 0;
}

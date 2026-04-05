int minimumIndex(int* capacity, int capacitySize, int itemSize) {
  int idx = -1;
  for (int i = 0; i < capacitySize; ++i) {
    if (capacity[i] >= itemSize &&
        (idx == -1 || capacity[i] < capacity[idx])) idx = i;
  }
  return idx;
}

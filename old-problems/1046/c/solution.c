int lastStoneWeight(int* stones, int stonesSize) {
  while (stonesSize > 1) {
    int largest = stones[0] > stones[1] ? 0 : 1;
    int nextLargest = stones[0] > stones[1] ? 1 : 0;

    for (int i = stonesSize - 1; i > 1; --i) {
      if (stones[i] > stones[largest]) {
        nextLargest = largest;
        largest = i;
      } else if (stones[i] > stones[nextLargest]) {
        nextLargest = i;
      }
    }

    if (stones[largest] == stones[nextLargest]) {
      if (largest < stonesSize - 2) {
        if (nextLargest < stonesSize - 2) {
          stones[largest] = stones[stonesSize - 2];
          stones[nextLargest] = stones[stonesSize - 1];
        } else {
          stones[largest] = nextLargest == stonesSize - 2
              ? stones[stonesSize - 1]
              : stones[stonesSize - 2];
        }
      } else {
        if (nextLargest < stonesSize - 2) {
          stones[nextLargest] = largest == stonesSize - 2
              ? stones[stonesSize - 1]
              : stones[stonesSize - 2];
        }
      }
      stonesSize -= 2;
    } else {
      stones[largest] -= stones[nextLargest];
      stones[nextLargest] = stones[stonesSize - 1];
      --stonesSize;
    }
  }

  return stonesSize == 0 ? 0 : stones[0];
}

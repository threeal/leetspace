void quickSort(
    char** names, int* heights, int low, int high);

char** sortPeople(
    char** names, int namesSize, int* heights, int heightsSize,
    int* returnSize) {
  (void)heightsSize;

  quickSort(names, heights, 0, namesSize - 1);

  *returnSize = namesSize;
  return names;
}

void quickSort(
    char** names, int* heights, int low, int high) {
  if (low >= high) return;

  int pivot = low - 1;
  for (int i = low; i < high; ++i) {
    if (heights[i] <= heights[high]) continue;
    ++pivot;

    char* tempName = names[pivot];
    names[pivot] = names[i];
    names[i] = tempName;

    int tempHeight = heights[pivot];
    heights[pivot] = heights[i];
    heights[i] = tempHeight;
  }

  ++pivot;
  char* tempName = names[pivot];
  names[pivot] = names[high];
  names[high] = tempName;

  int tempHeight = heights[pivot];
  heights[pivot] = heights[high];
  heights[high] = tempHeight;

  quickSort(names, heights, low, pivot - 1);
  quickSort(names, heights, pivot + 1, high);
}

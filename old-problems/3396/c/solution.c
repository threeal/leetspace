int minimumOperations(int* nums, int numsSize) {
  int indices[101] = {0};

  int i = 0;
  for (int j = 0; j < numsSize; ++j) {
    if (indices[nums[j]] > i) i = indices[nums[j]];
    indices[nums[j]] = j + 1;
  }

  return i % 3 == 0 ? i / 3 : i / 3 + 1;
}

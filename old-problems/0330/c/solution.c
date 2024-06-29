int minPatches(int* nums, int numsSize, int n) {
  unsigned int unavailable = 1;
  int patches = 0;

  int i = 0;
  while (unavailable <= (unsigned int)n) {
    if (i < numsSize && (unsigned int)nums[i] <= unavailable) {
      unavailable += nums[i];
      ++i;
    } else {
      unavailable += unavailable;
      ++patches;
    }
  }

  return patches;
}

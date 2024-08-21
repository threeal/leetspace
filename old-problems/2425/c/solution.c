int xorAllNums(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int sum = 0;
  if (nums2Size % 2 != 0) {
    for (int i = nums1Size - 1; i >= 0; --i) {
      sum ^= nums1[i];
    }
  }

  if (nums1Size % 2 != 0) {
    for (int i = nums2Size - 1; i >= 0; --i) {
      sum ^= nums2[i];
    }
  }

  return sum;
}

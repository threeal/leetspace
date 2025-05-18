int numberOfPairs(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
  int count = 0;
  for (int i2 = 0; i2 < nums2Size; ++i2) {
    const int div = nums2[i2] * k;
    for (int i1 = 0; i1 < nums1Size; ++i1) {
      if (nums1[i1] % div == 0) ++count;
    }
  }
  return count;
}

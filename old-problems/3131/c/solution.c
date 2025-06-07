int addedInteger(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  (void)nums2Size;
  int min1 = nums1[0], min2 = nums2[0];
  for (int i = 0; i < nums1Size; ++i) {
    if (nums1[i] < min1) min1 = nums1[i];
    if (nums2[i] < min2) min2 = nums2[i];
  }
  return min2 - min1;
}

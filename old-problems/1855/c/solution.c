int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int i = 0, j = 1;
  while (i < nums1Size && j < nums2Size) {
    if (nums1[i] > nums2[j]) ++i;
    ++j;
  }
  return j - i - 1;
}
